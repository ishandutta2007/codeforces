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

// int perm[] = {-1, 2, 4, 1, 3};

int query(int t, int i, int j, int x) {
    cout << "? " << t << " " << i << " " << j << " " << x << endl;
    int ret;
    cin >> ret;
    // if (t == 1) ret = max(min(x, perm[i]), min(x + 1, perm[j]));
    // else ret = min(max(x, perm[i]), max(x + 1, perm[j]));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int a = uniform_int_distribution<int>(1, n)(rng);
        vector<int> ret(n + 1), has(n + 1);
        for (int i=1; i<=n; i++)
            if (a != i) {
                int p = query(1, a, i, n - 1);
                if (has[p]) {
                    if (p == n - 1) {
                        // need to distinguish between ret[a] = n - 1 or ret[a] = n
                        int q = query(1, i, a, n - 1);
                        if (q == n)
                            ret[a] = n;
                        else
                            ret[a] = n - 1;
                    } else {
                        ret[a] = p;
                    }
                    for (int j=1; j<=n; j++)
                        if (j != p)
                            ret[has[j]] = j;
                    break;
                }
                has[p] = i;
            }
        if (!ret[a]) {
            // ret[a] = 1 or ret[a] = 2
            int p = query(2, a, a == 1 ? 2 : 1, 1);
            if (p == 1)
                ret[a] = 1;
            else
                ret[a] = 2;
            for (int j=1; j<=n; j++)
                if (j != p)
                    ret[has[j]] = j;
        }

        for (int i=1; i<=n; i++)
            if (!ret[i]) {
                assert(i != a);
                if (ret[a] > (n + 1) / 2) {
                    int p = query(2, i, a, 1);
                    if (p == ret[a])
                        p = query(1, a, i, n - 1);
                    assert(p != ret[a]);
                    ret[i] = p;
                } else {
                    int p = query(1, a, i, n - 1);
                    if (p == ret[a])
                        p = query(2, i, a, 1);
                    assert(p != ret[a]);
                    ret[i] = p;
                }
            }

        cout << "!";
        for (int i=1; i<=n; i++)
            cout << " " << ret[i];
        cout << endl;
    }

    return 0;
}