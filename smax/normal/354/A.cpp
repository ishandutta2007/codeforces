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

    int n, l, r, ql, qr;
    cin >> n >> l >> r >> ql >> qr;
    vector<int> w(n);
    for (int i=0; i<n; i++)
        cin >> w[i];

    int lsum = 0, rsum = accumulate(w.begin(), w.end(), 0), ret = rsum * r + qr * (n - 1);
    for (int i=0; i<n; i++) {
        lsum += w[i];
        rsum -= w[i];
        int lCnt = i + 1, rCnt = n - i - 1;
        ret = min(ret, lsum * l + rsum * r + max(lCnt > rCnt ? (lCnt - rCnt - 1) * ql : (rCnt - lCnt - 1) * qr, 0));
    }
    cout << ret << "\n";

    return 0;
}