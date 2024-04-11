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

const uint64_t MOD = (1ULL << 61) - 1;
const int BASE = [] () {
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 gen(seed ^ uint64_t(new uint64_t));
    uniform_int_distribution<int> dist(258, 2e9 - 1);
    int base = dist(gen);
    return base % 2 == 0 ? base - 1 : base;
} ();

uint64_t add(uint64_t a, uint64_t b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

uint64_t sub(uint64_t a, uint64_t b) {
    a -= b;
    if (a >= MOD)
        a += MOD;
    return a;
}

uint64_t mul(uint64_t a, uint64_t b) {
    uint64_t l1 = (uint32_t) a, h1 = a >> 32, l2 = (uint32_t) b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & MOD) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & MOD) + (ret >> 61);
    ret = (ret & MOD) + (ret >> 61);
    return ret - 1;
}

const uint64_t INV = [] () {
    uint64_t ret = 1, a = BASE;
    for (uint64_t b=MOD-2; b>0; b/=2) {
        if (b % 2) ret = mul(ret, a);
        a = mul(a, a);
    }
    return ret;
} ();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = (int) s.size();

    vector<uint64_t> pw(n + 1), up(n + 1), down(n + 1), left(n + 1), right(n + 1), all(n + 1);
    pw[0] = 1;
    for (int i=0; i<n; i++) {
        pw[i+1] = mul(pw[i], BASE);
        up[i+1] = add(mul(up[i], BASE), s[i] == 'U');
        down[i+1] = add(mul(down[i], BASE), s[i] == 'D');
        left[i+1] = add(mul(left[i], BASE), s[i] == 'L' ? BASE : 0);
        right[i+1] = add(mul(right[i], BASE), s[i] == 'R' ? INV : 0);
        all[i+1] = add(all[i], pw[i]);
    }

    auto query = [&] (const vector<uint64_t> &hsh, int l, int r) -> uint64_t {
        return sub(hsh[r+1], mul(hsh[l], pw[r-l+1]));
    };

    int ret = 0, firstU = n;
    for (int i=n-1; i>=0; i--) {
        if (s[i] == 'U')
            firstU = i;
        int RL = -1, width = -1;
        for (int j=i; j<n; j++) {
            if (RL == -1 && i % 2 == j % 2 && (j == n - 1 || s[j] != 'R' || s[j+1] != 'L')) {
                RL = j;
                j = firstU;
                if (j == n || s[RL] == 'L' || s[RL] == 'U')
                    break;
                if (s[RL] == 'D')
                    while (RL < n - 1 && s[RL+1] == 'L')
                        RL++;
                width = firstU - RL;
                // check first row is valid
                if (i + 2 * width > n || add(add(query(left, i, i + width - 1), query(right, i, i + width - 1)), query(up, i + width, i + 2 * width - 1)) != all[width])
                    break;
                // check if all middle rows are valid
                bool ok = true;
                for (int k=i+width; k+width<=j; k+=width)
                    if (k + 2 * width > n || add(add(query(left, k, k + width - 1), query(right, k, k + width - 1)), add(query(down, k - width, k - 1), query(up, k + width, k + 2 * width - 1))) != all[width]) {
                        ok = false;
                        break;
                    }
                if (!ok)
                    break;
            }
            if (RL == -1) {
                // check if of form RLRL...
                if ((j - i + 1) % 2 == 0)
                    ret++;
            } else {
                // check if all indegrees are 1
                if ((j - i + 1) % width == 0) {
                    // confirm if this is allowed to be last row
                    if (add(add(query(left, j - width + 1, j), query(right, j - width + 1, j)), query(down, j - 2 * width + 1, j - width)) == all[width])
                        ret++;
                    // confirm if this is allowed to be middle row
                    if (j + width >= n || add(add(query(left, j - width + 1, j), query(right, j - width + 1, j)), add(query(down, j - 2 * width + 1, j - width), query(up, j + 1, j + width))) != all[width])
                        break;
                }
            }
        }
    }
    cout << ret << "\n";

    return 0;
}