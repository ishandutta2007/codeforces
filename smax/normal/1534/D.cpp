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
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << "? 1" << endl;
    vector<int> cnt(2);
    vector<vector<int>> nodes(n);
    set<pair<int, int>> ret;
    for (int i=0; i<n; i++) {
        int d;
        cin >> d;
        cnt[d % 2]++;
        nodes[d].push_back(i);
        if (d == 1)
            ret.emplace(0, i);
    }
    cnt[0]--;
    int z = cnt[0] < cnt[1] ? 2 : 1;

    for (int i=z; i<n; i+=2) {
        for (int u : nodes[i]) {
            cout << "? " << u + 1 << endl;
            for (int v=0; v<n; v++) {
                int d;
                cin >> d;
                if (d == 1)
                    ret.emplace(min(u, v), max(u, v));
            }
        }
    }

    assert((int) ret.size() == n - 1);
    cout << "!\n";
    for (auto [u, v] : ret)
        cout << u + 1 << " " << v + 1 << "\n";
    cout.flush();

    return 0;
}