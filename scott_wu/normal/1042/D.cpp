#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
ll T;

typedef tree <pair <ll, int>, null_type, less<pair <ll, int> >, rb_tree_tag, tree_order_statistics_node_update> oset;
oset mm;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N >> T;

    ll csum = 0, ans = 0;
    mm.insert(make_pair(0, -1));
    for (int i = 0; i < N; i++)
    {
        ll x; cin >> x;
        csum += x;
        ans += mm.order_of_key(make_pair (csum - T, MAXN));
        mm.insert(make_pair(csum, i));
    }
    cout << N * (ll) (N + 1) / 2 - ans << "\n";
}