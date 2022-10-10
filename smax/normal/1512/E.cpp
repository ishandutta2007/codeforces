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
        int n, l, r, s;
        cin >> n >> l >> r >> s;
        l--, r--;

        vector<int> ret(r - l + 1);
        iota(ret.begin(), ret.end(), 1);
        s -= accumulate(ret.begin(), ret.end(), 0);
        if (s < 0) {
            cout << "-1\n";
            continue;
        }

        int lim = n - ret.back();
        for (int i=(int)ret.size()-1; i>=0; i--) {
            int change = min(lim, s);
            ret[i] += change;
            s -= change;
        }
        if (s > 0) {
            cout << "-1\n";
            continue;
        }

        DEBUG(ret);
        vector<bool> taken(n + 1);
        for (int x : ret)
            taken[x] = true;
        int j = 1;
        for (int i=0; i<l; i++) {
            while (taken[j])
                j++;
            cout << j << " ";
            taken[j] = true;
            j++;
        }
        for (int x : ret)
            cout << x << " ";
        DEBUG(j);
        for (int i=r+1; i<n; i++) {
            while (taken[j])
                j++;
            cout << j << " ";
            taken[j] = true;
            j++;
        }
        cout << "\n";
    }

    return 0;
}