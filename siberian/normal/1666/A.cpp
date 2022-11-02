#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

#define hash hash228

const int MOD = 1e9 + 7;
const int B = 37;

int add(int a, int b) {
    a += b;
    if (a >= MOD) return a - MOD;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) return a + MOD;
    return a;
}

int mul(int a, int b) {
    return (ll)a * b % MOD;
}

const int N = 2e4 + 10;
int n;
string a;
ll ans;

int pows[N];
int prefPows[N];

void buildPows() {
    pows[0] = 1;
    for (int i = 1; i < N; ++i) {
        pows[i] = mul(B, pows[i - 1]);
    }
    for (int i = 0; i < N; ++i) {
        prefPows[i] = pows[i];
        if (i > 0) {
            prefPows[i] = add(prefPows[i], prefPows[i - 1]);
        }
    }   
}

int hash[N][4];

int getHash(int id, int l, int r) {
    chkmin(r, n - 1);
    chkmax(l, 0);
    if (l > r) {
        return 0;
    }
    return sub(hash[r][id], l > 0 ? mul(pows[r - l + 1], hash[l - 1][id]) : 0);
}

constexpr int getId(char x) {
    if (x == 'L') {
        return 0;
    } else if (x == 'R') {
        return 1;
    } else if (x == 'U') {
        return 2;
    } else if (x == 'D') {
        return 3;
    } else {
        throw;
    }
}

constexpr int d[4] = {-1, 1, 0, 0};

void buildHash() {
    for (int id = 0; id < 4; ++id) {
        for (int i = 0; i < n; ++i) {
            hash[i][id] = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        int pos = i + d[getId(a[i])];
        if (pos < 0 || pos >= n) continue;
        ++hash[pos][getId(a[i])];
    }
    for (int id = 0; id < 4; ++id) {
        for (int i = 1; i < n; ++i) {
            hash[i][id] = add(mul(hash[i - 1][id], B), hash[i][id]);
        }
    }
}

int jump[N];

void buildJumps() {
    for (int l = 0; l < n; ++l) {
        jump[l] = -1;
        int r = l;
        while (r < n && getId(a[r]) == (r - l + 1) % 2) {
            ++r;
        }
        if ((r - l) % 2) --r;
        if (r == n) {
            continue;
        }
        if (a[r] == 'L' || a[r] == 'U') {
            continue;
        }
        if (a[r] == 'R') {
            int nxt = r;
            while (nxt < n && a[nxt] != 'U') {
                ++nxt;
            }
            if (nxt == n) {
                continue;
            }
            jump[l] = nxt - r;
        } else if (a[r] == 'D') {
            if (r + 1 == n) {
                continue;
            }
            int nxt = r + 1;
            while (nxt < n && a[nxt] == 'L') {
                ++nxt;
            }
            if (nxt == n) {
                continue;
            }
            --nxt;
            int fu = nxt + 1;
            while (fu < n && a[fu] != 'U') {
                ++fu;
            }
            if (fu == n) {
                continue;
            }
            jump[l] = fu - nxt;
        } else {
            assert(false);
        }
    }
}

void build() {
    buildPows();
    buildHash();
    buildJumps();
}

void calcTrivial() {
    for (int l = 0; l < n; ++l) {
        int r = l;
        while (r < n && getId(a[r]) == (r - l + 1) % 2) {
            ++r;
            if ((r - l) % 2 == 0) {
                ++ans;
            }
        }
    }
}

bool checkTrivial(int l, int r) {
    return getHash(getId('D'), l, r) == 0 && getHash(getId('U'), l, r) == 0;
}

bool checkMiddle(int l, int r) {
    if (a[l] == 'L' || a[r] == 'R') {
        return false;
    }
    int len = r - l + 1;
    int val = 0;
    val = add(val, getHash(getId('D'), l - len, r - len));
    val = add(val, getHash(getId('U'), l + len, r + len));
    val = add(val, mul(B, getHash(getId('L'), l, r - 1)));
    val = add(val, getHash(getId('R'), l + 1, r));
    return val == prefPows[len - 1];
}

bool checkTop(int l, int r) {
    if (a[l] == 'L' || a[r] == 'R') {
        return false;
    }
    if (getHash(getId('U'), l, r) != 0) {
        return false;
    }
    int len = r - l + 1;
    int val = 0;
    val = add(val, getHash(getId('U'), l + len, r + len));
    val = add(val, mul(B, getHash(getId('L'), l, r - 1)));
    val = add(val, getHash(getId('R'), l + 1, r));
    return val == prefPows[len - 1];
}

bool checkBottom(int l, int r) {
    if (a[l] == 'L' || a[r] == 'R') {
        return false;
    }
    if (getHash(getId('D'), l, r) != 0) {
        return false;
    }
    int len = r - l + 1;
    int val = 0;
    val = add(val, getHash(getId('D'), l - len, r - len));
    val = add(val, mul(B, getHash(getId('L'), l, r - 1)));
    val = add(val, getHash(getId('R'), l + 1, r));
    return val == prefPows[len - 1];
}

void calc() {
    calcTrivial();
    for (int l = 0; l < n; ++l) {
        int len = jump[l];
        if (len == -1) {
            continue;
        } 

        if (l + len - 1 + len >= n) continue;
        if (!checkTop(l, l + len - 1)) continue;

        bool fullOk = true;
        bool nonTrivial = !checkTrivial(l, l + len - 1);

        for (int r = l + len - 1 + len; r < n && fullOk; r += len) {
            nonTrivial |= !checkTrivial(r - len + 1, r);
            bool ok = nonTrivial;
            if (r > l + len - 1 + len) {
                bool check = checkMiddle(r - len - len + 1, r - len);
                ok &= check;
                fullOk &= check;
            }
            if (ok) {
                ok &= checkBottom(r - len + 1, r);
            }
            if (ok) { 
                ++ans;
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> a;
    n = a.size();
    build();
    calc();
    cout << ans << endl;
    return 0;
}