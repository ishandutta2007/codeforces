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

const int LOG = 17;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        vector<int> a(r - l + 1);
        vector<array<int, 2>> trie(1);
        for (int &x : a) {
            cin >> x;
            int u = 0;
            for (int i=LOG-1; i>=0; i--) {
                int j = x >> i & 1;
                if (!trie[u][j]) {
                    trie[u][j] = (int) trie.size();
                    trie.emplace_back();
                }
                u = trie[u][j];
            }
        }

        for (int y : a) {
            int x = l ^ y, u = 0, v = 0, mn = 0, mx = 0;
            for (int i=LOG-1; i>=0; i--) {
                int j = x >> i & 1;
                if (!trie[u][j])
                    j ^= 1;
                u = trie[u][j];
                mn |= ((x >> i & 1) ^ j) << i;
                j = (x >> i & 1) ^ 1;
                if (!trie[v][j])
                    j ^= 1;
                v = trie[v][j];
                mx |= ((x >> i & 1) ^ j) << i;
            }
            if (mn == l && mx == r) {
                cout << x << "\n";
                break;
            }
        }
    }

    return 0;
}