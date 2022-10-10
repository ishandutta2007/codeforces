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

string match = "abacaba";

bool ok(const string &s, int i) {
    for (int j=i; j<i+7; j++)
        if (j >= s.length() || (s[j] != '?' && s[j] != match[j-i]))
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        bool ans = false;
        for (int i=0; i<n-6; i++)
            if (ok(s, i)) {
                string r = s;
                for (int j=i; j<i+7; j++)
                    r[j] = match[j-i];
                for (int j=0; j<n; j++)
                    if (r[j] == '?')
                        r[j] = 'z';
                int cnt = 0;
                for (int j=0; j<n-6; j++) {
                    bool f = true;
                    for (int k=0; k<7; k++)
                        if (r[j+k] != match[k]) {
                            f = false;
                            break;
                        }
                    if (f)
                        cnt++;
                }
                if (cnt == 1) {
                    cout << "Yes\n" << r << "\n";
                    ans = true;
                    break;
                }
            }
        if (!ans)
            cout << "No\n";
    }

    return 0;
}