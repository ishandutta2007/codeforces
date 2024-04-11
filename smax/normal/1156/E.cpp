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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++;
else if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> p(n), pos(n + 1);
    for (int i=0; i<n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }

    int ret = 0;
    set<int> st{-1, n};
    for (int x=n; x>0; x--) {
        auto it = st.insert(pos[x]).first;
        int l = *prev(it), r = *next(it);
        if (pos[x] - l < r - pos[x]) {
            for (int i=l+1; i<pos[x]; i++)
                if (p[i] < x && pos[x] < pos[x - p[i]] && pos[x - p[i]] < r)
                    ret++;
        } else {
            for (int i=pos[x]+1; i<r; i++)
                if (p[i] < x && l < pos[x - p[i]] && pos[x - p[i]] < pos[x])
                    ret++;
        }
    }
    cout << ret << "\n";

    return 0;
}