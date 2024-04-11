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

    int l, b, f, n;
    cin >> l >> b >> f >> n;
    vector<int> x(n), pos(n);
    set<pair<int, int>> st{{l + f, -1}};
    for (int i=0; i<n; i++) {
        int t;
        cin >> t >> x[i];
        if (t == 1) {
            if (st.empty() || x[i] + f <= st.begin()->first) {
                pos[i] = 0;
                st.emplace(0, i);
            } else {
                pos[i] = -1;
                for (auto it=st.begin(); next(it)!=st.end(); it++)
                    if (it->first + x[it->second] + b + x[i] + f <= next(it)->first) {
                        pos[i] = it->first + x[it->second] + b;
                        st.emplace(it->first + x[it->second] + b, i);
                        break;
                    }
            }
            cout << pos[i] << "\n";
        } else {
            x[i]--;
            st.erase({pos[x[i]], x[i]});
        }
    }

    return 0;
}