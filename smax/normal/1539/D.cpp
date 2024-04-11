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
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<long long, long long>> a(n);
    long long sumA = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i].first >> a[i].second;
        sumA += a[i].first;
    }

    sort(a.begin(), a.end(), [] (const pair<long long, long long> &p, const pair<long long, long long> &q) -> bool {
        return p.second < q.second;
    });
    long long ret = 2 * sumA, la = 0, need = 0, low = 0;
    for (int i=0; i<n; i++) {
        // buy some prefix up to i for discounted price
        if (i > 0) {
            need += max(a[i].second - low, 0LL);
            low = max(low, a[i].second) + a[i].first;
        } else {
            low = a[i].first + a[i].second;
        }
        la += a[i].first;
        long long full = sumA - la, takeFromCur = 0;
        if (full < a[0].second) {
            takeFromCur = min(a[0].second - full, a[i].first);
            full = a[0].second;
        }
        long long allocateToNeed = full - a[0].second;
        ret = min(ret, 2 * full + max(need - allocateToNeed, 0LL) + la - takeFromCur);
    }
    cout << ret << "\n";

    return 0;
}