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

const int MAX = 1e6 + 5;

int lp[MAX];
uint64_t rnd[MAX];

uint64_t getHash(int n) {
    uint64_t ret = 0;
    while (n > 1) {
        int p = lp[n];
        while (n % p == 0) {
            ret ^= rnd[p];
            n /= p;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    iota(lp, lp + MAX, 0);
    for (int p=2; p<MAX; p++)
        if (lp[p] == p) {
            for (int i=p; i<MAX; i+=p)
                lp[i] = p;
            rnd[p] = rng();
        }

    int n;
    cin >> n;

    set<int> st;

    auto print = [&] () -> void {
        vector<int> ret;
        for (int i=1; i<=n; i++)
            if (!st.count(i))
                ret.push_back(i);
        cout << ret.size() << "\n";
        for (int x : ret)
            cout << x << " ";
        cout << "\n";
        exit(0);
    };

    // remove 0
    uint64_t tot = 0, cur = 0;
    for (int i=1; i<=n; i++) {
        cur ^= getHash(i);
        tot ^= cur;
    }
    if (tot == 0)
        print();

    // remove 1
    cur = 0;
    unordered_map<uint64_t, int> mp;
    for (int i=1; i<=n; i++) {
        cur ^= getHash(i);
        mp[cur] = i;
        if (tot == cur) {
            st.insert(i);
            print();
        }
    }

    // remove 2
    for (const auto &p : mp)
        if (mp.count(tot ^ p.first)) {
            st.insert(p.second);
            st.insert(mp[tot ^ p.first]);
            print();
        }

    // remove 3
    assert(n % 4 == 3);
    st.insert(2);
    st.insert(n / 2);
    st.insert(n);
    print();

    return 0;
}