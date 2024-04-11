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
        vector<int> q(n);
        for (int i=0; i<n; i++)
            cin >> q[i];

        set<int> st1, st2;
        for (int x=1; x<=n; x++) {
            st1.insert(x);
            st2.insert(x);
        }

        vector<int> mn, mx;
        for (int i=0; i<n; i++) {
            if (i == 0 || q[i] != q[i-1]) {
                mn.push_back(q[i]);
                mx.push_back(q[i]);
                st1.erase(q[i]);
                st2.erase(q[i]);
            } else {
                auto it = st1.begin();
                assert(*it < q[i]);
                mn.push_back(*it);
                st1.erase(it);
                it = st2.lower_bound(q[i]);
                assert(it != st2.begin());
                mx.push_back(*prev(it));
                st2.erase(prev(it));
            }
        }

        for (int x : mn)
            cout << x << " ";
        cout << "\n";
        for (int x : mx)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}