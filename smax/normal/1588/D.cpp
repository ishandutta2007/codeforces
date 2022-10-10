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

int encode(char c) {
    return c <= 'Z' ? c - 'A' : c - 'a' + 26;
}

char decode(int x) {
    return x < 26 ? char('A' + x) : char('a' + x - 26);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> s(n);
        vector<vector<vector<int>>> nxt;
        for (int i=0; i<n; i++) {
            cin >> s[i];
            nxt.emplace_back(s[i].size() + 1, vector<int>(52, (int) s[i].size()));
            for (int j=(int)s[i].size()-1; j>=0; j--)
                for (int k=0; k<52; k++)
                    nxt[i][j][k] = encode(s[i][j]) == k ? j : nxt[i][j+1][k];
        }

        map<vector<int>, int> dp;
        vector<int> idx(n);

        auto solve = [&] (auto &self) -> int {
            if (dp.count(idx))
                return dp[idx];
            int &ret = dp[idx];
            for (int c=0; c<52; c++) {
                bool ok = true;
                for (int i=0; i<n; i++)
                    if (nxt[i][idx[i]][c] == (int) s[i].size()) {
                        ok = false;
                        break;
                    }
                if (ok) {
                    vector<int> old = idx;
                    for (int i=0; i<n; i++)
                        idx[i] = nxt[i][idx[i]][c] + 1;
                    ret = max(ret, self(self) + 1);
                    idx = old;
                }
            }
            return ret;
        };

        int ret = solve(solve);
        cout << ret << "\n";
        while (ret--) {
            for (int c=0; c<52; c++) {
                bool ok = true;
                for (int i=0; i<n; i++)
                    if (nxt[i][idx[i]][c] == (int) s[i].size()) {
                        ok = false;
                        break;
                    }
                if (ok) {
                    vector<int> old = idx;
                    for (int i=0; i<n; i++)
                        idx[i] = nxt[i][idx[i]][c] + 1;
                    if (dp[idx] == ret) {
                        cout << decode(c);
                        goto done;
                    }
                    idx = old;
                }
            }
            done:;
        }
        cout << "\n";
    }

    return 0;
}