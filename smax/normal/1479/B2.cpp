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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++;
else if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];

    int ret = 0;
    vector<int> last(n + 1, -1), lpp(n + 1, -1), lp(2, -1);
    for (int i=0; i<n; ) {
        int j = i;
        while (j < n && a[i] == a[j])
            j++;
        if (last[a[i]] == -1) {
            DEBUG(i, a[i], 0, "ADD");
            lp[0] = i;
            lpp[a[i]] = 0;
            ret++;
        } else {
            // check if everything in between is of same pile
            if (!(lp[0] > last[a[i]] && lp[1] > last[a[i]])) {
                int pile = lp[0] > last[a[i]] ? 0 : 1;
                DEBUG(lp[0], lp[1], last[a[i]]);
                if (lpp[a[i]] == pile) {
                    // move it over
                    DEBUG(i, a[i], !pile, lp[0], lp[1]);
                    lp[!pile] = lp[pile];
                    lp[pile] = i;
                } else {
                    // we are fine
                    DEBUG(i, a[i], pile, lp[0], lp[1]);
                    lp[pile] = i;
                }
                lpp[a[i]] = pile;
            } else {
                DEBUG(i, a[i], 0, "ADD");
                lp[0] = i;
                lpp[a[i]] = 0;
                ret++;
            }
        }
        last[a[i]] = i;
        i = j;
    }
    cout << ret << "\n";

    return 0;
}