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

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> diff;

    // a / b
    auto frac = [&] (int a, int b) {
        if (b == 0) {
            if (a == 0)
                return make_pair(0, 1);
            return make_pair(INF, INF);
        } else {
            int g = __gcd(a, b);
            a /= g;
            b /= g;
            if (b < 0) {
                a = -a;
                b = -b;
            }
            DEBUG(a, b)
            return make_pair(a, b);
        }
    };

    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (i > 0) {
            diff.push_back(frac(a[i], a[i-1]));
        }
    }

    map<pair<int, int>, int> mp;
    for (auto &p : diff)
        mp[p]++;



    DEBUG(mp)
    if (mp.size() == 0 || (mp.size() == 1 && mp.begin()->first.first != INF)) {
        cout << "0\n";
        return 0;
    }
    // if (mp.size() > 2) {
    //     cout << "2\n";
    //     return 0;
    // }

    // is it all 0?
    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (a[i] == 0)
            cnt++;
    }
    if (cnt == n) {
        cout << "0\n";
        return 0;
    }
    if (cnt == n - 1) {
        if (a[0] != 0) {
            cout << "0\n";
            return 0;
        }
        cout << "1\n";
        return 0;
    }

    auto kill = [&] (const pair<int, int> &p) {
        if (--mp[p] == 0)
            mp.erase(p);
    };

    // try each
    for (int i=0; i<n; i++) {
        vector<pair<int, int>> add, rem;
        if (i > 0) {
            rem.push_back(frac(a[i], a[i-1]));
        }
        if (i + 1 < n) {
            rem.push_back(frac(a[i+1], a[i]));
        }
        if (i > 0 && i + 1 < n) {
            add.push_back(frac(a[i+1], a[i-1]));
        }
        DEBUG(i, add, rem)
        for (auto &p : add) {
            mp[p]++;
        }
        for (auto &p : rem) {
            kill(p);
        }
        DEBUG(i, mp)
        if (mp.size() == 0 || (mp.size() == 1 && mp.begin()->first.first != INF)) {
            cout << "1\n";
            return 0;
        }
        for (auto &p : add) {
            kill(p);
        }
        for (auto &p : rem) {
            mp[p]++;
        }
    }
    cout << "2\n";

    return 0;
}