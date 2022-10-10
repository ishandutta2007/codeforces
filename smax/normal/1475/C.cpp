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
        int a, b, k;
        cin >> a >> b >> k;
        vector<int> u(k), v(k), cntA(a), cntB(b);
        for (int i=0; i<k; i++) {
            cin >> u[i];
            cntA[--u[i]]++;
        }
        for (int i=0; i<k; i++) {
            cin >> v[i];
            cntB[--v[i]]++;
        }
        long long ret = (long long) k * (k - 1);
        for (int i=0; i<k; i++)
            ret -= cntA[u[i]] + cntB[v[i]] - 2, DEBUG(i, cntA[u[i]], cntB[u[i]]);
        cout << ret / 2 << "\n";
    }

    return 0;
}