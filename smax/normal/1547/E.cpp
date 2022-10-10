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

    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(k), t(k);
        for (int i=0; i<k; i++)
            cin >> a[i];
        for (int i=0; i<k; i++)
            cin >> t[i];

        vector<int> temp(n, -1);
        multiset<int> left, right;
        for (int i=0; i<k; i++) {
            temp[--a[i]] = t[i];
            right.insert(t[i] + a[i]);
        }

        int deltaL = 0, deltaR = 0;
        for (int i=0; i<n; i++) {
            DEBUG(left, right, deltaL, deltaR);
            int ret = INT_MAX;
            if (!left.empty())
                ret = min(ret, *left.begin() + deltaL);
            if (!right.empty())
                ret = min(ret, *right.begin() + deltaR);
            cout << ret << " ";
            if (temp[i] != -1) {
                left.insert(temp[i] - deltaL);
                right.erase(right.find(temp[i] - deltaR));
            }
            deltaL++;
            deltaR--;
        }
        cout << "\n";
    }

    return 0;
}