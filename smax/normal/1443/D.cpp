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
        vector<int> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];

        vector<int> orig = a;
        for (int rep=0; rep<2; rep++) {
            int i = 1, j = n - 2;
            while (i < n && a[i-1] >= a[i])
                i++;
            while (j >= 0 && a[j+1] >= a[j])
                j--;
            if (i > j) {
                cout << "YES\n";
                goto done;
            }
            multiset<int> st;
            for (int k=i-1; k<=j; k++)
                st.insert(a[k]);
            int delta = 0, oldJ = j;
            while (j >= i && !st.empty() && *st.begin() > delta) {
                int mn = max(min(*st.begin() - delta, a[j] - delta - a[j+1]), 0);
                delta += mn;
                st.erase(st.find(a[j]));
                a[j] -= delta;
                j--;
            }
            for (int k=i-1; k<=j; k++)
                a[k] -= delta;
            j = oldJ;
            while (i < n && a[i-1] >= a[i])
                i++;
            while (j >= 0 && a[j+1] >= a[j])
                j--;
            if (i > j) {
                cout << "YES\n";
                goto done;
            }
            a = orig;
            reverse(a.begin(), a.end());
        }
        cout << "NO\n";
        done:;
    }

    return 0;
}