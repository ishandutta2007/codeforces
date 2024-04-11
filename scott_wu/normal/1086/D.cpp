#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N, Q;
int cv[MAXN];

typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
oset locs[3];


int conv (char c)
{
    if (c == 'R')
        return 0;
    if (c == 'S')
        return 1;
    if (c == 'P')
        return 2;
    exit(0);
}

int get_res (int me)
{
    int bud = (me + 1) % 3, demon = (me + 2) % 3;
    if (!locs[demon].size())
    {
        return locs[me].size();
    }

    if (!locs[bud].size())
        return 0;
    int dlo = *locs[demon].begin(), dhi = *locs[demon].rbegin();
    int blo = *locs[bud].begin(), bhi = *locs[bud].rbegin();
    int ctot = locs[me].size();
    // subtract out guys in [dlo, blo] and [bhi, dhi]
    if (dlo <= blo)
    {
        ctot -= (locs[me].order_of_key(blo) - locs[me].order_of_key(dlo));
    }
    if (bhi <= dhi)
    {
        ctot -= (locs[me].order_of_key(dhi) - locs[me].order_of_key(bhi));
    }
    return ctot;
}

int get_ans()
{
    int res = 0;
    for (int i = 0; i < 3; i++)
    {
        res += get_res (i);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> Q;
    for (int i = 0; i < N; i++)
    {
        char c; cin >> c;
        cv[i] = conv (c);
        locs[cv[i]].insert(i);
    }

    cout << get_ans() << "\n";
    for (int i = 0; i < Q; i++)
    {
        int x; char c;
        cin >> x >> c;
        x--;
        locs[cv[x]].erase(x);
        cv[x] = conv (c);
        locs[cv[x]].insert(x);

        cout << get_ans() << "\n";
    }
}