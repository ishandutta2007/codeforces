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

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    if (k == 0) {
        cout << n << "\n";
        for (int i=1; i<=n; i++)
            cout << i << " ";
        cout << "\n";
        return 0;
    }

    int b = __lg(k), mask = (1 << 30) - (1 << (b + 1));
    vector<int> ret;
    sort(a.begin(), a.end());
    for (int i=0; i<n; ) {
        int j = i;
        while (j < n && (a[i].first & mask) == (a[j].first & mask))
            j++;
        vector<array<int, 2>> trie(1);
        vector<int> nd(1);
        bool ok = false;
        for (int l=i; l<j; l++) {
            int u = 0;
            bool above = false, found = true;
            for (int x=b; x>=0; x--) {
                int nxt = ~a[l].first >> x & 1;
                if (!trie[u][nxt]) {
                    nxt ^= 1;
                    if ((!above && k >> x & 1) || !trie[u][nxt]) {
                        found = false;
                        break;
                    }
                } else {
                    if (~k >> x & 1)
                        above = true;
                }
                u = trie[u][nxt];
            }
            if (found) {
                ret.push_back(a[l].second);
                ret.push_back(nd[u]);
                ok = true;
                break;
            }
            u = 0;
            for (int x=b; x>=0; x--) {
                int nxt = a[l].first >> x & 1;
                if (!trie[u][nxt]) {
                    trie[u][nxt] = (int) trie.size();
                    trie.emplace_back();
                    nd.emplace_back();
                }
                u = trie[u][nxt];
            }
            nd[u] = a[l].second;
        }
        if (!ok)
            ret.push_back(a[i].second);
        i = j;
    }

    if (ret.size() < 2) {
        cout << "-1\n";
    } else {
        cout << ret.size() << "\n";
        for (int i : ret)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}