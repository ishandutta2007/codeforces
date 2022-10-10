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

#define int long long

bool isPower(int x, int m) {
    while (x % m == 0)
        x /= m;
    return x == 1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int &x : a)
            cin >> x;
        int k;
        cin >> k;
        vector<int> b(k);
        for (int &x : b)
            cin >> x;

        bool ok = true;
        int i = 0, sum = 0;
        deque<pair<int, int>> que;
        for (int j=0; j<k; j++) {
            while (i < n && sum < b[j]) {
                int x = a[i], cnt = 1;
                while (x % m == 0) {
                    x /= m;
                    cnt *= m;
                }
                que.emplace_back(x, cnt);
                sum += a[i++];
            }
            DEBUG(i, j, a, b, que);
            if (sum < b[j]) {
                ok = false;
                break;
            }
            vector<pair<int, int>> stk;
            int targ = b[j];
            while (targ > 0) {
                auto [x, cnt] = que.front();
                que.pop_front();
                sum -= x * cnt;
                // leave residual
                if (x * cnt > targ) {
                    if ((x * cnt - targ) % x != 0) {
                        ok = false;
                        break;
                    }
                    que.emplace_front(x, (x * cnt - targ) / x);
                    sum += x * cnt - targ;
                    cnt -= (x * cnt - targ) / x;
                }
                targ -= x * cnt;
                DEBUG(x, cnt, targ, que);
                // merge with previous group
                vector<pair<int, int>> pending;
                while (!stk.empty()) {
                    auto [y, ycnt] = stk.back();
                    stk.pop_back();
                    if (y % x || !isPower(y / x, m)) {
                        ok = false;
                        break;
                    }
                    int gcnt = 1;
                    while (x < y) {
                        x *= m;
                        gcnt *= m;
                    }
                    if (cnt % gcnt)
                        pending.emplace_back(x, cnt % gcnt);
                    x = y;
                    cnt /= gcnt;
                    if (cnt == 0)
                        break;
                    cnt += ycnt;
                }
                if (!ok)
                    break;
                while (!pending.empty()) {
                    stk.push_back(pending.back());
                    pending.pop_back();
                }
                if (cnt > 0)
                    stk.emplace_back(x, cnt);
                DEBUG(stk, que);
            }
            DEBUG(stk, que);
            ok &= targ == 0 && stk.size() == 1 && isPower(stk.back().second, m) && stk.back().first * stk.back().second == b[j];
            if (!ok)
                break;
        }
        ok &= i == n && sum == 0;
        cout << (ok ? "Yes" : "No") << "\n";
    }

    return 0;
}