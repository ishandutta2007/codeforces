#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 1000005;

template <typename T> inline void read(T &WOW) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	WOW = flag * x;
}

int n, cnt;
bool vis[MAXN], ban[MAXN];
int pr[MAXN], pcnt;
ULL val[MAXN], hs[MAXN];

inline ULL Rand() {
    return (ULL)rand() * rand() * rand() * rand();
}

void prework() {
    for (int i = 2; i <= n; ++i) {
        val[i] = Rand();
    }
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) {
            pr[++pcnt] = i;
            hs[i] = val[i];
        }
        for (int j = 1; j <= pcnt && i * pr[j] <= n; ++j) {
            vis[i * pr[j]] = 1;
            hs[i * pr[j]] = hs[i] ^ val[pr[j]];
            if (i % pr[j] == 0) break;
        }
    }
    for (int i = 2; i <= n; ++i) {
        hs[i] ^= hs[i - 1];
    }
}

map<ULL, int> mp;

void Calc() {
    ULL cur = 0;
    for (int i = 1; i <= n; ++i) {
        cur ^= hs[i];
        mp[hs[i]] = i;
    }
    if (!cur) {
        cnt = 0;
        return;
    }
    if (mp.count(cur)) {
        cnt = 1;
        ban[mp[cur]] = 1;
        return;
    }
    for (int i = 2; i <= n; ++i) {
        if (mp.count(cur ^ hs[i]) && mp[cur ^ hs[i]] != i) {
            cnt = 2;
            ban[i] = ban[mp[cur ^ hs[i]]] = 1;
            return;
        }
    }
    cnt = 3;
    ban[2] = ban[n / 2] = ban[n] = 1;
    return;
}

void solve() {
    srand((unsigned)time(NULL));
    read(n);
    prework();
    Calc();
    printf("%d\n", n - cnt);
    for (int i = 1; i <= n; ++i) {
        if (!ban[i]) printf("%d ", i);
    }
}

int main() {
    solve();
    return 0;
}