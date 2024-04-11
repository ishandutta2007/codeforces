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

int n, k, a[500005];
bool ban[500005];

int solve(int l, int r) {
    if (l > r)
        return 0;
    multiset<int> st;
    for (int i=l; i<=r; i++) {
        if ((l > 0 && a[i] < a[l-1]) || (r + 1 < n && a[i] > a[r+1]))
            continue;
        auto it = st.upper_bound(a[i]);
        if (it != st.end())
            st.erase(it);
        st.insert(a[i]);
    }
    return r - l + 1 - (int) st.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
    for (int i=0; i<k; i++) {
        int b;
        cin >> b;
        ban[--b] = true;
    }

    int ret = k == 0 ? solve(0, n - 1) : 0, i = 0;
    bool first = true;
    while (i < n) {
        if (ban[i]) {
            if (first) {
                ret += solve(0, i - 1);
                first = false;
            }
            int j = i + 1;
            while (j < n && !ban[j])
                j++;
            if (j < n && a[i] > a[j]) {
                cout << "-1\n";
                return 0;
            }
            ret += solve(i + 1, j - 1);
            i = j;
        } else {
            i++;
        }
    }
    cout << ret << "\n";

    return 0;
}