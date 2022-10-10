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

long long solve(int i, vector<int> &a) {
    if (i == -1 || a.empty())
        return 0;
    auto mid = partition(a.begin(), a.end(), [&] (int x) -> bool {
        return x >> i & 1;
    });
    vector<int> left(a.begin(), mid), right(mid, a.end());
    long long ret = solve(i - 1, left) + solve(i - 1, right);
    if (!left.empty() && !right.empty()) {
        vector<array<int, 2>> trie(1);
        for (int x : left) {
            int u = 0;
            for (int j=29; j>=0; j--) {
                int b = x >> j & 1;
                if (!trie[u][b]) {
                    trie[u][b] = (int) trie.size();
                    trie.emplace_back();
                }
                u = trie[u][b];
            }
        }
        int mn = INT_MAX;
        for (int x : right) {
            int u = 0, y = 0;
            for (int j=29; j>=0; j--) {
                int b = x >> j & 1;
                if (!trie[u][b])
                    b ^= 1;
                u = trie[u][b];
                y |= b << j;
            }
            mn = min(mn, x ^ y);
        }
        ret += mn;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];
    cout << solve(29, a) << "\n";

    return 0;
}