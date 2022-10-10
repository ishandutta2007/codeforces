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
        vector<int> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];

        vector<int> l(n), r(n);
        set<int> st;
        for (int i=0; i<n; i++) {
            l[i] = i == 0 ? n - 1 : i - 1;
            r[i] = i == n - 1 ? 0 : i + 1;
            if (__gcd(a[i], a[r[i]]) == 1)
                st.insert(r[i]);
        }

        vector<int> ret;
        int last = 0;
        while (!st.empty()) {
            auto it = st.upper_bound(last);
            if (it == st.end())
                it = st.begin();
            int i = *it;
            ret.push_back(i);
            if ((int) ret.size() == n)
                break;
            r[l[i]] = r[i];
            l[r[i]] = l[i];
            st.erase(it);
            if (__gcd(a[i], a[r[i]]) == 1)
                st.erase(r[i]);
            if (__gcd(a[l[i]], a[r[i]]) == 1)
                st.insert(r[i]);
            last = r[i];
        }

        cout << ret.size();
        for (int x : ret)
            cout << " " << x + 1;
        cout << "\n";
    }

    return 0;
}