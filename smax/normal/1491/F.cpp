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

    auto ask = [&] (const vector<int> &a, const vector<int> &b) -> int {
        cout << "? " << a.size() << " " << b.size() << endl;
        for (int x : a)
            cout << x + 1 << " ";
        cout << endl;
        for (int x : b)
            cout << x + 1 << " ";
        cout << endl;
        int ret;
        cin >> ret;
        return ret;
    };

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        // find second magnet
        vector<int> a{0};
        int pos;
        for (pos=1; pos<n; pos++) {
            if (ask(a, {pos}) != 0)
                break;
            a.push_back(pos);
        }
        assert(pos < n);

        // identify magnets [pos + 1, n - 1]
        vector<int> ret;
        for (int i=pos+1; i<n; i++)
            if (ask({pos}, {i}) == 0)
                ret.push_back(i);

        // we know there exists exactly one magnet in [0, pos - 1], which we can find with binary search
        int l = 0, r = (int) a.size();
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (ask({pos}, vector<int>(a.begin() + l, a.begin() + m)) != 0)
                r = m;
            else
                l = m;
        }
        for (int x : a)
            if (x != l)
                ret.push_back(x);

        cout << "! " << ret.size();
        for (int x : ret)
            cout << " " << x + 1;
        cout << endl;
    }

    return 0;
}