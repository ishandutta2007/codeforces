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
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> trie{vector<int>(26)};
    for (int i=1; i<=n; i++) {
        int p;
        char c;
        cin >> p >> c;
        trie[p][c-'a'] = i;
        trie.emplace_back(26);
    }
    vector<int> query(n + 1, -1);
    int k;
    cin >> k;
    for (int i=0; i<k; i++) {
        int a;
        cin >> a;
        query[a] = i;
    }

    int delta = 0;
    vector<int> dp, mn, ret(k);

    auto dfs = [&] (auto &self, int u) -> void {
        if (query[u] != -1) {
            ret[query[u]] = min(dp.back() + 1, mn.back() + delta + 1);
            dp.push_back(ret[query[u]]);
            mn.push_back(min(mn.back(), ret[query[u]] - delta));
            delta++;
        } else {
            dp.push_back(dp.empty() ? 0 : dp.back() + 1);
            mn.push_back(min(mn.empty() ? INT_MAX : mn.back(), dp.back() - delta));
        }
        for (int c=0; c<26; c++)
            if (trie[u][c])
                self(self, trie[u][c]);
        dp.pop_back();
        mn.pop_back();
    };

    dfs(dfs, 0);
    for (int i=0; i<k; i++)
        cout << ret[i] << " ";
    cout << "\n";

    return 0;
}