#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int MD = 1000000007;

#define ll long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define FOR(i, a, b) for (int _tmp = b, i = a; i <= _tmp; ++i)

typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vvi;

int n, m, q, cnt[N];
int fi[N], a[N];
int l[N], r[N], lst[N];
ll val[N];

int main()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    fi[1] = fi[2] = 1 % m;
    for (int i = 3; i < N; ++i)
        fi[i] = (fi[i - 1] + fi[i - 2]) % m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> q;
    vector < pii > v;
    for (int i = 1; i <= n; ++i)
        v.pb(mp(a[i], i));
    sort(v.begin(), v.end());
    FOR(i, 1, q)
        cin >> l[i] >> r[i];
    for (int i = 0; i < v.size(); ++i) {
        int x = v[i].first, y = v[i].second;
        FOR(j, 1, q)
            if (l[j] <= y && y <= r[j] && lst[j] < x) {
                lst[j] = x;
                cnt[j]++;
                val[j] += 1LL * fi[cnt[j]] * x;
            }
    }
    FOR(i, 1, q)
        cout << val[i] % m << '\n';
    return 0;
}