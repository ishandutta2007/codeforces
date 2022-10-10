#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

const int MAX = 3e7 + 5;
const int MAXN = 1e5 + 5;
const int SQ = 448;
const int MOD = 1e9 + 7;

bitset<SQ> prime;
vector<int> primeList;

void sieve() {
    prime.set();
    prime[0] = prime[1] = 0;
    primeList.push_back(2);
    for (int i=4; i<SQ; i+=2)
        prime[i] = 0;
    for (int p=3; p<SQ; p+=2)
        if (prime[p]) {
            primeList.push_back(p);
            for (int i=p; i<=(SQ-1)/p; i+=2)
                prime[i*p] = 0;
        }
}

int power(long long a, int b) {
    long long ret = 1;
    for (; b>0; b/=2) {
        if (b % 2) ret = ret * a % MOD;
        a = a * a % MOD;
    }
    return ret;
}

int inverse(int a) {
    return power(a, MOD - 2);
}

int id = 1, pl[MAX], pr[MAX], st[MAX];

int newLeaf(int val) {
    int p = id++;
    pl[p] = pr[p] = 0;
    st[p] = val;
    return p;
}

int newParent(int a, int b) {
    int p = id++;
    pl[p] = a;
    pr[p] = b;
    st[p] = (long long) st[a] * st[b] % MOD;
    return p;
}

int query(int p, int l, int r, int i, int j) {
    if (i > r || j < l)
        return 1;
    if (i <= l && r <= j)
        return st[p];

    int m = (l + r) / 2;
    return (long long) query(pl[p], l, m, i, j) * query(pr[p], m+1, r, i, j) % MOD;
}

int update(int p, int l, int r, int idx, int val) {
    if (l == r)
        return newLeaf((long long) st[p] * val % MOD);

    int m = (l + r) / 2;
    if (idx <= m)
        return newParent(update(pl[p], l, m, idx, val), pr[p]);
    return newParent(pl[p], update(pr[p], m+1, r, idx, val));
}

int root[MAXN];
vector<pair<int, int>> stk[2*MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    st[0] = 1;

    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a;
        cin >> a;
        int x = a;
        map<int, int> mp;
        for (int p : primeList) {
            if (p > x / p)
                break;
            if (x % p == 0) {
                int cnt = 0;
                while (x % p == 0) {
                    x /= p;
                    cnt++;
                }
                int cur = cnt;
                while (cur > 0 && !stk[p].empty()) {
                    auto &[amt, pos] = stk[p].back();
                    int change = min(amt, cur);
                    amt -= change;
                    cur -= change;
                    if (amt == 0)
                        stk[p].pop_back();
                    if (!mp.count(pos))
                        mp[pos] = 1;
                    mp[pos] = (long long) mp[pos] * power(p, change) % MOD;
                }
                stk[p].emplace_back(cnt, i);
            }
        }
        if (x > 1) {
            if (!stk[x].empty()) {
                auto &[amt, pos] = stk[x].back();
                amt--;
                if (amt == 0)
                    stk[x].back();
                if (!mp.count(pos))
                    mp[pos] = 1;
                mp[pos] = (long long) mp[pos] * x % MOD;
            }
            stk[x].emplace_back(1, i);
        }
        root[i] = root[i-1];
        for (auto [pos, val] : mp)
            root[i] = update(root[i], 1, n, pos, inverse(val));
        root[i] = update(root[i], 1, n, i, a);
    }

    int q, last = 0;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x = (last + x) % n + 1, y = (last + y) % n + 1;
        if (x > y)
            swap(x, y);
        last = query(root[y], 1, n, x, y);
        cout << last << "\n";
    }

    return 0;
}