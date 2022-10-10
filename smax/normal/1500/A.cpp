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

const int MAX = 5e6 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];

    vector<vector<pair<int, int>>> pairs(MAX);
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++) {
            for (auto &p : pairs[a[i] + a[j]])
                if (p.first != i && p.first != j && p.second != i && p.second != j) {
                    cout << "YES\n" << i + 1 << " " << j + 1 << " " << p.first + 1 << " " << p.second + 1 << "\n";
                    return 0;
                }
            pairs[a[i] + a[j]].emplace_back(i, j);
            if (pairs[a[i] + a[j]].size() == 4) {
                vector<int> indices;
                for (auto &p : pairs[a[i] + a[j]]) {
                    indices.push_back(p.first);
                    indices.push_back(p.second);
                }
                for (int w : indices)
                    for (int x : indices)
                        if (x != w)
                            for (int y : indices)
                                if (y != w && y != x)
                                    for (int z : indices)
                                        if (z != w && z != x && z != y && a[w] + a[x] == a[y] + a[z]) {
                                            cout << "YES\n" << w + 1 << " " << x + 1 << " " << y + 1 << " " << z + 1 << "\n";
                                            return 0;
                                        }
                assert(false);
            }
        }
    cout << "NO\n";

    return 0;
}