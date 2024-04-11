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

const int MAX = 1e7 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> sum(MAX, 1), ret(MAX);
    for (int p=2; p<MAX; p++)
        if (sum[p] == 1) {
            for (int i=p; i<MAX; i+=p) {
                int term = 1, x = i, pw = p;
                while (x % p == 0) {
                    term += pw;
                    x /= p;
                    pw *= p;
                }
                sum[i] *= term;
            }
        }
    DEBUG(*max_element(sum.begin(), sum.end()));
    for (int i=1; i<MAX; i++)
        if (sum[i] < MAX && !ret[sum[i]])
            ret[sum[i]] = i;

    int t;
    cin >> t;
    while (t--) {
        int c;
        cin >> c;
        cout << (ret[c] ? ret[c] : -1) << "\n";
    }

    return 0;
}