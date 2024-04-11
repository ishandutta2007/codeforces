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

int n, k, a[N];
ll b, s[N];

int main()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> b;
    FOR(i, 1, n) {
        cin >> a[i];
        s[i] = a[i] + s[i - 1];
    }
    int res = n;
    multiset < int > st;
    ll sum = 0;
    for (int i = n - 1; i >= 1; --i) {
        if (b - sum < a[i]) {
            res = i;
        }
        if (st.size() < k - 1 || st.size() == k - 1 && k > 1 && *st.begin() < a[i]) {
            if (st.size() == k - 1) {
                sum -= *st.begin();
                st.erase(st.begin());
            }
            sum += a[i];
            st.insert(a[i]);
        }
    }
    cout << res << endl;
    return 0;
}