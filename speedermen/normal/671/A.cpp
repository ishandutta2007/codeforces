#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int MD = 1000000007;

#define ll long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define FOR(i, a, b) for (int _tmp = (b), i = (a); i <= _tmp; ++i)

typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef pair < long double, long double > pdd;

pdd pt[N];
long double da[N], db[N];

int main()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    pdd a, b, t;
    cin >> a.x >> a.y >> b.x >> b.y >> t.x >> t.y;
    int n;
    cin >> n;
    FOR(i, 0, n - 1) cin >> pt[i].x >> pt[i].y;
    long double fans = 0, ma = 1e40, mb = 1e40;
    vector < long double > A(n), B(n);
    multiset < pdd > ab, ba;
    FOR(i, 0, n - 1) {
        da[i] = hypotl(pt[i].x - a.x, pt[i].y - a.y);
        db[i] = hypotl(pt[i].x - b.x, pt[i].y - b.y);
        fans += 2 * hypotl(pt[i].x - t.x, pt[i].y - t.y);
        A[i] = da[i] - hypotl(pt[i].x - t.x, pt[i].y - t.y);
        B[i] = db[i] - hypotl(pt[i].x - t.x, pt[i].y - t.y);
        ab.insert(mp(A[i], B[i]));
        ba.insert(mp(B[i], A[i]));
    }
    long double ans = 1e40;
    FOR(i, 0, n - 1) {
        ab.erase(mp(A[i], B[i]));
        ba.erase(mp(B[i], A[i]));
        ans = min(ans, A[i] + (!ba.empty() ? min((long double)0.0, ba.begin()->first) : 0));
        ans = min(ans, B[i] + (!ab.empty() ? min((long double)0.0, ab.begin()->first) : 0));
        ab.insert(mp(A[i], B[i]));
        ba.insert(mp(B[i], A[i]));
    }
    cout.precision(10);
    cout << fixed << fans + ans << endl;
    return 0;
}