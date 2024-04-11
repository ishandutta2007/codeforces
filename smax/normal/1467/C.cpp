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

    vector<int> n(3);
    for (int i=0; i<3; i++)
        cin >> n[i];
    long long sum = 0;
    vector<vector<int>> a(3);
    vector<int> mn(3, INT_MAX), mn2(3, INT_MAX);
    for (int i=0; i<3; i++) {
        a[i].resize(n[i]);
        for (int j=0; j<n[i]; j++) {
            cin >> a[i][j];
            sum += a[i][j];
            if (a[i][j] <= mn[i]) {
                mn2[i] = mn[i];
                mn[i] = a[i][j];
            } else if (a[i][j] < mn2[i]) {
                mn2[i] = a[i][j];
            }
        }
    }

    long long ret = LLONG_MIN;
    for (int fin=0; fin<3; fin++)
        for (int suck=0; suck<3; suck++)
            if (fin != suck) {
                if (n[suck] == 1) {
                    ret = max(ret, sum - 2LL * mn[suck]);
                } else if (n[suck] == 2) {
                    int other = 3 - fin - suck;
                    ret = max(ret, sum - 2LL * mn[suck] - 2LL * min(mn[other], mn2[suck]));
                } else {
                    long long huh = accumulate(a[suck].begin(), a[suck].end(), 0LL) - mn[suck];
                    int other = 3 - fin - suck;
                    ret = max(ret, sum - 2LL * mn[suck] - 2LL * min((long long) mn[other], huh));
                }
            }
    cout << ret << "\n";

    return 0;
}