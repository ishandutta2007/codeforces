#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
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
        int n, k;
        string s;
        cin >> n >> k >> s;

        sort(s.begin(), s.end());
        char last = s.back();
        vector<string> ss(k);
        bool done = false, pack = false;
        for (int i=0, j=0; j<n; j++) {
            if (done) {
                if (s[j] != last || ss[0][0] != ss[k-1][0] || pack) {
                    pack = true;
                    ss[0] += s[j];
                } else {
                    ss[i++] += s[j];
                    if (i == k)
                        i = 0;
                }
            } else
                ss[i++] += s[j];
            if (i == k) {
                done = true;
                i = 0;
            }
        }

        string ret;
        for (string r : ss)
            ret = max(ret, r);
        cout << ret << "\n";
    }

    return 0;
}