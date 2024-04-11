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
        long long k;
        cin >> k;

        if (k % 2) {
            cout << "-1\n";
            continue;
        }
        vector<long long> ret{1};
        k -= 2;
        long long power = 4;
        while (k > 0) {
            if (k >= power) {
                ret.push_back(0);
                k -= power;
                power *= 2;
            } else {
                ret.push_back(1);
                k -= 2;
                power = 4;
            }
        }
        assert(ret.size() <= 2000);
        cout << ret.size() << "\n";
        for (long long x : ret)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}