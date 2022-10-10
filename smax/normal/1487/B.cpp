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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        k--;
        if (n % 2 == 0) {
            cout << k % n + 1 << "\n";
        } else {
            k %= (long long) n * (n / 2);
            if (k == 0) {
                cout << "1\n";
                continue;
            }
            k--;
            int times = k / (n - 2), rem = k % (n - 2), skip1, skip2;
            DEBUG("INIT", times, rem);
            if (times == 0)
                skip1 = n / 2, skip2 = INT_MAX;
            else
                skip1 = times - 1, skip2 = skip1 + (n + 1) / 2;
            if (times == 0)
                rem++;
            if (rem >= skip1)
                rem++;
            if (rem >= skip2)
                rem++;
            DEBUG(n, k, times, rem, skip1, skip2);
            cout << rem + 1 << "\n";
        }
    }

    return 0;
}