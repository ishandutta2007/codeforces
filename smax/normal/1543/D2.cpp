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
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        auto get = [&] (int x) -> vector<int> {
            vector<int> ret;
            while (x > 0) {
                ret.push_back(x % k);
                x /= k;
            }
            return ret;
        };

        auto comb = [&] (vector<int> &a, vector<int> &b) -> void {
            a.resize(max(a.size(), b.size()));
            b.resize(max(a.size(), b.size()));
            for (int i=0; i<(int)a.size(); i++)
                a[i] = (a[i] + b[i]) % k;
        };

        auto inv = [&] (vector<int> &a) {
            for (int i=0; i<(int)a.size(); i++)
                a[i] = (k - a[i]) % k;
        };

        auto val = [&] (const vector<int> &a) -> int {
            int ret = 0;
            for (int i=(int)a.size()-1; i>=0; i--)
                ret = ret * k + a[i];
            return ret;
        };

        bool flipped = false;
        vector<int> asked;
        for (int i=0; i<n; i++) {
            vector<int> cur = get(i);
            if (flipped)
                inv(cur);
            comb(cur, asked);
            cout << val(cur) << endl;
            int r;
            cin >> r;
            assert(r != -1);
            if (r == 1)
                break;
            flipped ^= true;
            inv(asked);
            comb(asked, cur);
        }
    }

    return 0;
}