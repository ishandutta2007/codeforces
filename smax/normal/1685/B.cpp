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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        string s;
        cin >> a >> b >> c >> d >> s;
        int n = (int) s.size();

        int cntA = (int) count(s.begin(), s.end(), 'A'), cntB = (int) count(s.begin(), s.end(), 'B');
        if (a + c + d != cntA || b + c + d != cntB) {
            cout << "NO\n";
            continue;
        }

        int odd = 0;
        vector<int> ab, ba;
        for (int i=0; i<n; ) {
            int j = i;
            while (j + 1 < n && s[j] != s[j+1])
                j++;
            if (s[i] == s[j])
                odd += (j - i) / 2;
            else if (s[i] == 'A')
                ab.push_back((j - i + 1) / 2);
            else
                ba.push_back((j - i + 1) / 2);
            i = j + 1;
        }
        sort(ab.begin(), ab.end());
        sort(ba.rbegin(), ba.rend());

        // first use AB strings
        for (int &x : ab) {
            int change = min(x, c);
            x -= change;
            c -= change;
        }
        // then use odds
        {
            int change = min(odd, c);
            odd -= change;
            c -= change;
        }
        // finally use BA strings
        for (int &x : ba)
            if (c > 0 && x > 1) {
                int change = min(x - 1, c);
                x -= change + 1;
                c -= change;
            }
        if (c > 0) {
            cout << "NO\n";
            continue;
        }

        // check if rest is sufficient
        for (int x : ab)
            d -= max(x - 1, 0);
        for (int x : ba)
            d -= x;
        d -= odd;
        cout << (d > 0 ? "NO" : "YES") << "\n";
    }

    return 0;
}