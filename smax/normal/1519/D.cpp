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

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<n; i++)
        cin >> b[i];

    vector<long long> pref(n), suff(n);
    for (int i=0; i<n; i++)
        pref[i] = (long long) a[i] * b[i] + (i > 0 ? pref[i-1] : 0);
    for (int i=n-1; i>=0; i--)
        suff[i] = (long long) a[i] * b[i] + (i + 1 < n ? suff[i+1] : 0);

    long long ret = pref[n-1];
    for (int i=0; i<n; i++) {
        int l = i, r = i;
        long long cur = 0;
        while (l >= 0 && r < n) {
            cur += (long long) a[l] * b[r] + (l == r ? 0 : (long long) a[r] * b[l]);
            ret = max(ret, cur + (l > 0 ? pref[l-1] : 0) + (r + 1 < n ? suff[r+1] : 0));
            l--;
            r++;
        }
        l = i;
        r = i + 1;
        cur = 0;
        while (l >= 0 && r < n) {
            cur += (long long) a[l] * b[r] + (long long) a[r] * b[l];
            ret = max(ret, cur + (l > 0 ? pref[l-1] : 0) + (r + 1 < n ? suff[r+1] : 0));
            l--;
            r++;
        }
    }
    cout << ret << "\n";

    return 0;
}