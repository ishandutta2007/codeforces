#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<bool> vis(2 * n);
        vector<pair<int, int>> chords;
        for (int i=0; i<k; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            vis[x] = vis[y] = true;
            chords.emplace_back(min(x, y), max(x, y));
        }

        DEBUG(vis);
        for (int i=0, rep=0; i<2*n; i++)
            if (!vis[i]) {
                rep++;
                if (rep > n - k)
                    break;
                int j = i + 1, cnt = 0;
                while (cnt < n - k) {
                    if (!vis[j])
                        cnt++;
                    if (cnt == n - k)
                        break;
                    j++;
                }
                chords.emplace_back(i, j);
            }
        assert((int) chords.size() == n);
        DEBUG(chords);

        int ret = 0;
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
                if ((chords[i].first < chords[j].first && chords[j].first < chords[i].second && chords[i].second < chords[j].second)
                 || (chords[j].first < chords[i].first && chords[i].first < chords[j].second && chords[j].second < chords[i].second))
                    ret++;
        cout << ret << "\n";
    }

    return 0;
}