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
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i=0; i<n; i++)
            cin >> p[i];
        string s;
        cin >> s;

        vector<vector<int>> indices(2);
        for (int i=0; i<n; i++)
            indices[s[i] == '1'].push_back(i);

        auto cmp = [&] (int i, int j) -> bool {
            return p[i] < p[j];
        };

        sort(indices[0].begin(), indices[0].end(), cmp);
        sort(indices[1].begin(), indices[1].end(), cmp);
        vector<int> ret(n);
        for (int i=0; i<(int)indices[0].size(); i++)
            ret[indices[0][i]] = i + 1;
        for (int i=0; i<(int)indices[1].size(); i++)
            ret[indices[1][i]] = i + 1 + (int) indices[0].size();

        for (int x : ret)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}