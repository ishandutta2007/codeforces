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

int cost(int n) {
    return n == 0 ? 1 : (n & (n - 1)) == 0 ? 0 : (1 << (__lg(n) + 1)) - n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> cnt(n);
        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            cnt[--a]++;
        }

        int i = 0, sum = 0, ret = INT_MAX;
        for (int pw=1; pw<=2*n; pw*=2) {
            while (i < n && sum + cnt[i] <= pw)
                sum += cnt[i++];
            DEBUG(t, i, pw, sum);
            if (i == n) {
                ret = min(ret, pw - sum + 2);
            } else {
                int left = 0, right = accumulate(cnt.begin() + i, cnt.end(), 0);
                ret = min(ret, pw - sum + cost(right) + 1);
                for (int j=i; j<n; j++) {
                    left += cnt[j];
                    right -= cnt[j];
                    DEBUG(t, i, j, sum, left, right);
                    ret = min(ret, pw - sum + cost(left) + cost(right));
                }
            }
        }
        cout << ret << "\n";
    }

    return 0;
}