#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int MD = 1000000007;

#define ll long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(x) (int)((x).size())
#define FOR(i, a, b) for (int _tmp = (b), i = (a); i <= _tmp; ++i)

typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef pair < long double, long double > pdd;

int n, a[N], b[N];
int ia[N], ib[N];

int main()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    FOR(i, 1, n) cin >> a[i], ia[a[i]] = i;
    FOR(i, 1, n) cin >> b[i], ib[b[i]] = i;
    int res = 0, pre = 0;
    FOR(i, 1, n) {
        if (ib[a[i]] > pre) {
            pre = ib[a[i]];
            res++;
        } else {
            break;
        }
    }
    cout << n - res << endl;
    return 0;
}