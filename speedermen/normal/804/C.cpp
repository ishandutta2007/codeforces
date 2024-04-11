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

int n, m, ans[N], cnt;
vi s[N], g[N];

bool cmp(int a, int b) {
    return ans[a] < ans[b];
}

void go(int v, int p) {
    sort(s[v].begin(), s[v].end(), cmp);
    int f = cnt, bc = sz(s[v]) - 1;
    for (auto w : s[v]) {
        if (ans[w] == 0) {
            while (bc >= 0 && ans[s[v][bc]] == f) {
                f--;
                bc--;
            }
            ans[w] = f--;
        }
    }
    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        go(to, v);
    }
}

int main()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    FOR(i, 1, n) {
        int k;
        cin >> k;
        cnt = max(cnt, k);
        s[i].resize(k);
        for (auto &x : s[i]) {
            cin >> x;
        }
    }
    FOR(i, 1, n - 1) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    go(1, 0);
    cout << max(cnt, 1) << "\n";
    FOR(i, 1, m) {
        cout << max(ans[i], 1) << " \n"[i == m];
    }
    return 0;
}