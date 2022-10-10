#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i=0; i<2*n; i++) {
        char c;
        cin >> c;
        if (c == '+') {
            v.emplace_back(0, 0);
        } else {
            int x;
            cin >> x;
            v.emplace_back(1, x);
        }
    }

    set<int> st;
    vector<int> stk;
    for (int i=2*n-1; i>=0; i--) {
        if (v[i].first == 0) {
            if (st.empty()) {
                cout << "NO\n";
                return 0;
            }
            stk.push_back(*st.begin());
            st.erase(st.begin());
        } else {
            if (!st.empty() && v[i].second > *st.begin()) {
                cout << "NO\n";
                return 0;
            }
            st.insert(v[i].second);
        }
    }
    cout << "YES\n";
    reverse(stk.begin(), stk.end());
    for (int x : stk)
        cout << x << " ";
    cout << "\n";

    return 0;
}