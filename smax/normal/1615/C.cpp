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

// const int LIM = 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;

        array<array<int, 2>, 2> init{};
        for (int i=0; i<n; i++)
            init[a[i] - '0'][b[i] - '0']++;
        // for (int i=0; i<2; i++)
        //     for (int j=0; j<2; j++)
        //         init[i][j] = min(init[i][j], LIM);

        map<array<array<int, 2>, 2>, int> dist;
        queue<array<array<int, 2>, 2>> que;
        dist[init] = 0;
        que.push(init);
        while (!que.empty()) {
            auto cnt = que.front();
            que.pop();
            DEBUG(cnt, dist[cnt]);
            if (cnt[0][1] == 0 && cnt[1][0] == 0) {
                cout << dist[cnt] << "\n";
                goto done;
            }
            if (cnt[1][0] > 0) {
                array<array<int, 2>, 2> nxt;
                nxt[0][0] = cnt[1][0] - 1;
                nxt[0][1] = cnt[1][1];
                nxt[1][0] = cnt[0][0] + 1;
                nxt[1][1] = cnt[0][1];
                // for (int i=0; i<2; i++)
                //     for (int j=0; j<2; j++)
                //         nxt[i][j] = min(nxt[i][j], LIM);
                if (!dist.count(nxt)) {
                    dist[nxt] = dist[cnt] + 1;
                    que.push(nxt);
                }
            }
            if (cnt[1][1] > 0) {
                array<array<int, 2>, 2> nxt{};
                nxt[0][0] = cnt[1][0];
                nxt[0][1] = cnt[1][1] - 1;
                nxt[1][0] = cnt[0][0];
                nxt[1][1] = cnt[0][1] + 1;
                // for (int i=0; i<2; i++)
                //     for (int j=0; j<2; j++)
                //         nxt[i][j] = min(nxt[i][j], LIM);
                if (!dist.count(nxt)) {
                    dist[nxt] = dist[cnt] + 1;
                    que.push(nxt);
                }
            }
        }
        cout << "-1\n";
        done:;
    }

    return 0;
}