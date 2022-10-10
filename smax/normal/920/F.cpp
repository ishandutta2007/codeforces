#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

#define MAXN 300000
#define MAX 1000001

bitset<MAX> prime;
vector<int> primeList;

void sieve() {
    prime.set();
    prime[0] = prime[1] = 0;
    primeList.push_back(2);
    for (int i=4; i<MAX; i+=2)
        prime[i] = 0;
    for (int p=3; p<MAX; p+=2)
        if (prime[p]) {
            primeList.push_back(p);
            if (p < 1000)
                for (int i=p*p; i<MAX; i+=2*p)
                    prime[i] = 0;
        }
}

int a[MAXN], onetwo[4*MAXN], nxt[MAX];
long long st[4*MAXN];

void preprocess() {
    sieve();
    for (int i=1; i<MAX; i++) {
        int x = i, numDiv = 1;
        for (int p : primeList) {
            if (1LL * p * p > x)
                break;
            if (x % p == 0) {
                int cnt = 0;
                while (x % p == 0) {
                    x /= p;
                    cnt++;
                }
                numDiv *= cnt + 1;
            }
        }
        if (x > 1)
            numDiv *= 2;
        nxt[i] = numDiv;
    }
}

void build(int p, int l, int r) {
    if (l == r) {
        st[p] = a[l];
        onetwo[p] = (a[l] == 1 || a[l] == 2);
        return;
    }

    int m = (l + r) / 2;
    build(2*p, l, m);
    build(2*p+1, m+1, r);
    st[p] = st[2*p] + st[2*p+1];
    onetwo[p] = onetwo[2*p] + onetwo[2*p+1];
}

long long query(int p, int l, int r, int i, int j) {
    if (i > r || j < l)
        return 0;
    if (i <= l && r <= j)
        return st[p];

    int m = (l + r) / 2;
    return query(2*p, l, m, i, j) + query(2*p+1, m+1, r, i, j);
}

void down(int p, int l, int r) {
    if (l == r) {
        st[p] = nxt[st[p]];
        onetwo[p] = (st[p] == 1 || st[p] == 2);
        return;
    }

    int m = (l + r) / 2;
    if (onetwo[2*p] < m - l + 1)
        down(2*p, l, m);
    if (onetwo[2*p+1] < r - m)
        down(2*p+1, m+1, r);
    st[p] = st[2*p] + st[2*p+1];
    onetwo[p] = onetwo[2*p] + onetwo[2*p+1];
}

void update(int p, int l, int r, int i, int j) {
    if (i > r || j < l)
        return;
    if (i <= l && r <= j) {
        if (onetwo[p] < r - l + 1)
            down(p, l, r);
        return;
    }

    int m = (l + r) / 2;
    update(2*p, l, m, i, j);
    update(2*p+1, m+1, r, i, j);
    st[p] = st[2*p] + st[2*p+1];
    onetwo[p] = onetwo[2*p] + onetwo[2*p+1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    preprocess();

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> a[i];

    build(1, 0, n-1);
    while (m--) {
        int t, l, r;
        cin >> t >> l >> r;
        l--, r--;

        if (t == 1)
            update(1, 0, n-1, l, r);
        else
            cout << query(1, 0, n-1, l, r) << "\n";
    }

    return 0;
}