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

    auto query = [] (int b, const pair<int, int> &p) -> void {
        cout << b << " " << p.first + 1 << " " << p.second + 1 << endl;
    };

    int n;
    cin >> n;
    vector<vector<pair<int, int>>> diag(2);
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            diag[(i + j) % 2].emplace_back(i, j);
    for (int rep=0; rep<n*n; rep++) {
        int a;
        cin >> a;
        if (a == 1) {
            if (!diag[1].empty()) {
                query(2, diag[1].back());
                diag[1].pop_back();
            } else {
                query(3, diag[0].back());
                diag[0].pop_back();
            }
        } else {
            if (!diag[0].empty()) {
                query(1, diag[0].back());
                diag[0].pop_back();
            } else {
                query(a == 3 ? 2 : 3, diag[1].back());
                diag[1].pop_back();
            }
        }
    }

    return 0;
}