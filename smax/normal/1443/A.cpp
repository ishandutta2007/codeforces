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
        vector<int> a;
        // for (int i=4; i<=4*n && (int)a.size()<n; i+=2) {
        //     bool ok = true;
        //     for (int j : a)
        //         ok &= i % j != 0;
        //     if (ok)
        //         a.push_back(i);
        // }
        for (int i=4*n; i>0 && (int)a.size()<n; i--) {
            // if (find(a.begin(), a.end(), i) != a.end())
            //     continue;
            bool ok = true;
            for (int j : a)
                ok &= __gcd(i, j) != 1 && i % j != 0 && j % i != 0;
            if (ok)
                a.push_back(i);
        }
        DEBUG(a, a.size())
        assert((int) a.size() == n);
        for (int x : a)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}