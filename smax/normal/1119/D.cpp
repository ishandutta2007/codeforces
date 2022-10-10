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
    vector<long long> s(n);
    for (int i=0; i<n; i++)
        cin >> s[i];

    sort(s.begin(), s.end());
    vector<long long> diff;
    for (int i=1; i<n; i++)
        diff.push_back(s[i] - s[i-1]);
    sort(diff.begin(), diff.end());
    vector<long long> pref;
    partial_sum(diff.begin(), diff.end(), back_inserter(pref));

    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        long long l, r;
        cin >> l >> r;
        int pos = int(lower_bound(diff.begin(), diff.end(), r - l + 1) - diff.begin());
        cout << r - l + 1 + (pos > 0 ? pref[pos-1] : 0) + (r - l + 1) * (n - pos - 1) << " ";
    }
    cout << "\n";

    return 0;
}