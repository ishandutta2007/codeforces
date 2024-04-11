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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> pts(n);
        for (int i=0; i<n; i++)
            cin >> pts[i].first;
        for (int i=0; i<n; i++)
            cin >> pts[i].second;

        sort(pts.begin(), pts.end());
        pts.insert(pts.begin(), {1, 1});
        long long ret = 0;
        for (int i=0; i<n; i++) {
            if (pts[i] == pts[i+1])
                continue;
            if ((pts[i].first + pts[i].second) % 2) {
                int r = pts[i].first + (pts[i+1].second - pts[i].second);
                assert(r <= pts[i+1].first);
                ret += (pts[i+1].first - r + 1) / 2;
            } else {
                int r = pts[i].first + (pts[i+1].second - pts[i].second);
                assert(r <= pts[i+1].first);
                if (r == pts[i+1].first)
                    ret += pts[i+1].second - pts[i].second;
                else
                    ret += (pts[i+1].first - r) / 2;
            }
        }
        cout << ret << "\n";
    }

    return 0;
}