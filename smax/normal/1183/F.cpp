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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;

        set<int> st;
        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            st.insert(a);
        }

        int mx = *st.rbegin(), ret = 0;
        if (mx % 2 == 0 && mx % 3 == 0 && mx % 5 == 0 && st.count(mx / 2) && st.count(mx / 3) && st.count(mx / 5))
            ret = mx / 2 + mx / 3 + mx / 5;

        vector<int> best;
        while (!st.empty() && best.size() < 3) {
            int x = *st.rbegin();
            st.erase(x);

            bool ok = true;
            for (int y : best)
                ok &= (y % x != 0);
            if (ok)
                best.push_back(x);
        }

        cout << max(ret, accumulate(best.begin(), best.end(), 0)) << "\n";
    }

    return 0;
}