#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int a[500], b[500];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> a[i];
        for (int i=0; i<n; i++)
            cin >> b[i];

        if (n % 2 && a[n/2] != b[n/2]) {
            cout << "No\n";
            continue;
        }

        multiset<pair<int, int>> st;
        for (int i=0; i<n/2; i++) {
            if (a[i] > a[n-i-1])
                swap(a[i], a[n-i-1]);
            st.insert({a[i], a[n-i-1]});
        }

        bool ok = true;
        for (int i=0; i<n/2; i++) {
            if (b[i] > b[n-i-1])
                swap(b[i], b[n-i-1]);
            auto it = st.find({b[i], b[n-i-1]});
            if (it == st.end()) {
                ok = false;
                break;
            }
            st.erase(it);
        }

        cout << (ok ? "Yes" : "No") << "\n";
    }

    return 0;
}