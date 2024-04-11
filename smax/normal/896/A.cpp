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
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

const long long INF = 1e18;
const string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string fi1 = "What are you doing while sending \"";
const string fi2 = "\"? Are you busy? Will you send \"";
const string fi3 = "\"?";

long long dp[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[0] = f0.size();
    for (int i=1; i<=100000; i++)
        dp[i] = min(2 * dp[i-1] + (int) (fi1.size() + fi2.size() + fi3.size()), INF);

    int q;
    cin >> q;
    while (q--) {
        int n;
        long long k;
        cin >> n >> k;

        if (k > dp[n]) {
            cout << '.';
            continue;
        }

        for (int i=n; i>0; i--) {
            if (k <= (int) fi1.size()) {
                cout << fi1[k-1];
                goto done;
            }
            k -= fi1.size();
            if (k <= dp[i-1])
                continue;
            k -= dp[i-1];
            if (k <= (int) fi2.size()) {
                cout << fi2[k-1];
                goto done;
            }
            k -= fi2.size();
            if (k <= dp[i-1])
                continue;
            k -= dp[i-1];
            cout << fi3[k-1];
            goto done;
        }
        cout << f0[k-1];
        done:;
    }
    cout << "\n";

    return 0;
}