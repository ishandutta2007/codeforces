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
        long long n;
        int s;
        cin >> n >> s;

        vector<int> v(20);
        for (int i=(int)v.size()-1; i>=0; i--) {
            v[i] = n % 10;
            n /= 10;
        }

        // case 1: keep same
        vector<int> pref(20);
        for (int i=1; i<20; i++)
            pref[i] = pref[i-1] + v[i];
        if (pref[19] <= s) {
            cout << "0\n";
            continue;
        }

        // case 2: increment one digit, set rest to 0
        long long ret = LLONG_MAX, power = 1, cur = 0;
        for (int i=19; i>0; i--) {
            if (v[i] < 9 && pref[i-1] + v[i] + 1 <= s)
                ret = min(ret, power - cur);
            cur += v[i] * power;
            power *= 10;
        }
        cout << ret << "\n";
    }

    return 0;
}