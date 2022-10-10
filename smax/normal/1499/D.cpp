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

const int MAX = 2e7 + 5;

int cnt[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int p=2; p<MAX; p++)
        if (cnt[p] == 0)
            for (int i=p; i<MAX; i+=p)
                cnt[i]++;

    int t;
    cin >> t;
    while (t--) {
        long long c, d, x;
        cin >> c >> d >> x;

        vector<long long> v;
        for (long long g=1; g*g<=x; g++)
            if (x % g == 0) {
                v.push_back(g);
                if (x / g != g) v.push_back(x / g);
            }

        long long ret = 0;
        for (long long g : v) {
            long long cur = x / g + d;
            if (cur % c == 0)
                ret += 1 << cnt[cur / c];
        }
        cout << ret << "\n";
    }

    return 0;
}