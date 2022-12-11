#include <bits/stdc++.h>
using namespace std;

void init() {
//#if __GLIBCXX__ == 20160609
#ifdef FIRE_MIND
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#else
    ///freopen(TASKNAME".in", "r", stdin);
    ///freopen(TASKNAME".out", "w", stdout);
#endif
}
#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const double EPS = 1e-9;
const int INF = (int)1e9 + 41;
const int N = (int)1e5 + 34;
int mx = 11;

unordered_set <int> mis[N];
int u[N], cnt = 1;
int ans[N];
int n, m, a, b;

int len[N];

int main() {
    init();

    ans[0] = 0;
    ans[1] = 0;
    ans[2] = 0;
    ans[3] = 0;
    for (int i = 4; i < N; i++)
        ans[i] = ans[i / 2] + 1;

    cin >> n;
    string s[223];
    for (int iq = 0; iq < n; iq++) {
        cin >> s[iq];
        cnt++;
        int m = s[iq].length();
        int x;
        for (int len = 1; len <= mx; len++) {
            for (int i = 0; i + len <= m; i++) {
                x = 0;
                for (int j = i; j < i + len; j++) {
                    x = x * 2 + (int)(s[iq][j] == '1');
                }
                x += (1 << len);
                u[x] = cnt;
            }
        }
        for (int i = 2; i < (2 << mx); i++)
            if (u[i] != cnt) {
                mis[iq].insert(i);
            }
    }

    cin >> m;
    for (int iq = n; iq < n + m; iq++) {
        cin >> a >> b;
        a--;
        b--;
        int as = s[a].length();
        int bs = s[b].length();

        cnt++;
        for (int l = 1; l < mx; l++)
        for (int r = 1; l + r <= mx; r++) {
            if (l + r == 0 || l > as || r > bs) continue;
            int x = 0;
            for (int i = as - l; i < as; i++)
                x = x * 2 + (int)(s[a][i] == '1');
            for (int i = 0; i < r; i++)
                x = x * 2 + (int)(s[b][i] == '1');
            x += (1 << (l + r));
            u[x] = cnt;
        }

        int sm = INF;
        for (auto x: mis[a]) {
            if (mis[b].find(x) != mis[b].end() && u[x] != cnt) {
                mis[iq].insert(x);
                sm = min(sm, x);
            }
        }

        s[iq] = s[a] + s[b];
        int sz = s[iq].length();
        if (sz > mx * 2) {
            string tmp;
            for (int i = 0; i < mx; i++) tmp.push_back(s[iq][i]);
            for (int i = sz - mx; i < sz; i++) tmp.push_back(s[iq][i]);
            s[iq] = tmp;
        }

        //cerr << sm << " ";
        cout << ans[sm] << "\n";
        //cerr << s[iq] << " | " << st[iq] << " | " << fn[iq] << "\n";
    }

    //cout << mis[0].size() << "\n";

    return 0;
}