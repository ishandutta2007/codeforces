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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<array<int, 3>> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i][0] >> a[i][1];
            a[i][2] = i;
        }
        for (int i=0; i<n; i++)
            a.push_back({a[i][1], a[i][0], a[i][2]});

        sort(a.begin(), a.end());
        vector<int> ret(n, -2);
        set<pair<int, int>> st;
        for (int i=0; i<2*n; ) {
            int j = i;
            while (j < 2 * n && a[i][0] == a[j][0]) {
                auto it = st.upper_bound({a[j][1], INT_MIN});
                if (it != st.begin())
                    ret[a[j][2]] = prev(it)->second;
                j++;
            }
            for (int k=i; k<j; k++)
                st.emplace(a[k][1], a[k][2]);
            i = j;
        }

        for (int i=0; i<n; i++)
            cout << ret[i] + 1 << " ";
        cout << "\n";
    }

    return 0;
}