#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ordered_set = tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update >;
const int N = 200005;
int n, q, A[N];
ordered_set S[3];
inline int Query()
{
    int tot = 0;
    for (int i = 0; i < 3; i++)
    {
        int wn = (i + 1) % 3, ls = (i + 2) % 3;
        if (!S[ls].size())
            continue;
        if (!S[wn].size())
        {
            tot += S[i].size();
            continue;
        }

        int l = *S[ls].begin(), r = *S[wn].begin();
        int ri = *S[ls].rbegin(), le = *S[wn].rbegin();

        if (r < l) l = r = 0;
        if (ri < le) ri = le = n + 1;

        tot += S[i].order_of_key(r) - S[i].order_of_key(l);
        tot += S[i].order_of_key(ri) - S[i].order_of_key(le);
    }
    return (n - tot);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        if (ch == 'R') A[i] = 0;
        if (ch == 'S') A[i] = 1;
        if (ch == 'P') A[i] = 2;

        S[A[i]].insert(i);
    }
    cout << Query() << "\n";
    for (; q; q --)
    {
        int id; char ch;
        cin >> id >> ch;

        S[A[id]].erase(id);

        if (ch == 'R') A[id] = 0;
        if (ch == 'S') A[id] = 1;
        if (ch == 'P') A[id] = 2;

        S[A[id]].insert(id);

        cout << Query() << "\n";
    }
    return (0);
}