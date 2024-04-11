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

int solve(const vector<int> &a, int l, int x) {
    int n = a.size();
    if (l >= n)
        return 0;
    int i = l, ret = 0;
    while (i < n) {
        int j = i, cur = 0;
        while (j < n && cur < x)
            cur += a[j++];
        if (cur != x)
            return 1e9;
        ret += j - i - 1;
        i = j;
    }
    return ret;
}

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

        int ret = INT_MAX, sum = 0;
        for (int i=0; i<n; i++) {
            sum += a[i];
            ret = min(ret, i + solve(a, i + 1, sum));
        }
        cout << ret << "\n";
    }

    return 0;
}