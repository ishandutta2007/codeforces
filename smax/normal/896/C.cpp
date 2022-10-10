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

const int MOD = 1e9 + 7;

long long power(long long a, long long b, long long m) {
    long long ret = 1 % m;
    a %= m;
    for (; b>0; b/=2) {
        if (b % 2) ret = ret * a % m;
        a = a * a % m;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, seed, vmax;
    cin >> n >> m >> seed >> vmax;

    auto rnd = [&] () -> int {
        int ret = seed;
        seed = (seed * 7LL + 13) % MOD;
        return ret;
    };

    vector<int> a(n);
    for (int i=0; i<n; i++)
        a[i] = rnd() % vmax + 1;

    set<array<long long, 3>> st;
    for (int i=0; i<n; ) {
        int j = i;
        while (j < n && a[i] == a[j])
            j++;
        st.insert({i, j - 1, a[i]});
        i = j;
    }

    for (int i=0; i<m; i++) {
        int op = rnd() % 4 + 1, l = rnd() % n, r = rnd() % n;
        if (l > r)
            swap(l, r);
        if (op == 3) {
            // find xth
            int x = rnd() % (r - l + 1) + 1;
            auto it = prev(st.lower_bound({l + 1, 0, 0}));
            auto cur = *it;
            it++;
            vector<pair<long long, int>> ret;
            if (cur[1] > r)
                ret.emplace_back(cur[2], r - l + 1);
            else
                ret.emplace_back(cur[2], cur[1] - l + 1);
            while (it != st.end() && (*it)[0] <= r) {
                if ((*it)[1] > r) {
                    ret.emplace_back((*it)[2], r - (*it)[0] + 1);
                    break;
                }
                ret.emplace_back((*it)[2], (*it)[1] - (*it)[0] + 1);
                it++;
            }
            sort(ret.begin(), ret.end());
            for (auto [e, sz] : ret) {
                if (sz >= x) {
                    cout << e << "\n";
                    break;
                }
                x -= sz;
            }
        } else {
            int x = rnd() % vmax + 1;
            if (op == 1) {
                // range add x
                auto it = prev(st.lower_bound({l + 1, 0, 0}));
                auto cur = *it;
                it = st.erase(it);
                if (cur[0] < l)
                    it = next(st.insert({cur[0], l - 1, cur[2]}).first);
                if (cur[1] > r) {
                    st.insert({l, r, cur[2] + x});
                    it = st.insert({r + 1, cur[1], cur[2]}).first;
                } else {
                    it = next(st.insert({l, cur[1], cur[2] + x}).first);
                }
                while (it != st.end() && (*it)[0] <= r) {
                    cur = *it;
                    st.erase(it);
                    if (cur[1] > r) {
                        st.insert({cur[0], r, cur[2] + x});
                        st.insert({r + 1, cur[1], cur[2]});
                        break;
                    }
                    it = next(st.insert({cur[0], cur[1], cur[2] + x}).first);
                }
            } else if (op == 2) {
                // range set x
                auto it = prev(st.lower_bound({l + 1, 0, 0}));
                auto cur = *it;
                it = st.erase(it);
                if (cur[0] < l)
                    it = next(st.insert({cur[0], l - 1, cur[2]}).first);
                if (cur[1] > r)
                    it = st.insert({r + 1, cur[1], cur[2]}).first;
                while (it != st.end() && (*it)[0] <= r) {
                    if ((*it)[1] > r) {
                        cur = *it;
                        st.erase(it);
                        st.insert({r + 1, cur[1], cur[2]});
                        break;
                    }
                    it = st.erase(it);
                }
                st.insert({l, r, x});
            } else {
                // range add xth power
                int y = rnd() % vmax + 1, ret = 0;
                auto it = prev(st.lower_bound({l + 1, 0, 0}));
                auto cur = *it;
                it++;
                if (cur[1] > r)
                    ret += power(cur[2], x, y) * (r - l + 1) % y;
                else
                    ret += power(cur[2], x, y) * (cur[1] - l + 1) % y;
                if (ret >= y)
                    ret -= y;
                while (it != st.end() && (*it)[0] <= r) {
                    if ((*it)[1] > r) {
                        ret += power((*it)[2], x, y) * (r - (*it)[0] + 1) % y;
                        if (ret >= y)
                            ret -= y;
                        break;
                    }
                    ret += power((*it)[2], x, y) * ((*it)[1] - (*it)[0] + 1) % y;
                    if (ret >= y)
                        ret -= y;
                    it++;
                }
                cout << ret << "\n";
            }
        }
    }

    return 0;
}