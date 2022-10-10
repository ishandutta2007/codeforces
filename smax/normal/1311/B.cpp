#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int a[105], b[105];
bool can[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        memset(can, false, sizeof(can));
        for (int i=0; i<m; i++) {
            int p;
            cin >> p;
            can[p] = true;
        }

        bool ok = true;
        sort(b + 1, b + n + 1);
        vector<bool> visited(n + 1);
        for (int i=1; i<=n; i++) {
            int j = 1;
            while (a[j] != b[i] || visited[j])
                j++;
            visited[j] = true;
            for (int k=i; k<j; k++)
                if (!can[k]) {
                    ok = false;
                    break;
                }
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}