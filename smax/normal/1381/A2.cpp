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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;

        string orig = a;
        vector<int> ret;
        int lPtr = 1, rPtr = n - 2;
        for (int i=n-1; i>=0; i--) {
//            DEBUG(i, a[0], a[i], b[i])
            if (b[i] == a[0]) {
                ret.push_back(0);
                a[0] = (a[0] == '1' ? '0' : '1');
            }
            ret.push_back(i);
            DEBUG(i, a[0], a[i])
            if (i > 0 && i < n - 1)
                a[i] = (i % 2 == n % 2 ? orig[lPtr++] == '1' ? '0' : '1' : orig[rPtr--]);
            DEBUG(a[i])
            a[0] = (a[i] == '1' ? '0' : '1');
        }

        cout << ret.size() << "\n";
        for (int x : ret)
            cout << x + 1 << " ";
        cout << "\n";
    }

    return 0;
}