#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = (1 << 16) + 5;

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

int n, k, m;
int par[MAXN];

void solve() {
    read(n); read(k);
    if (n == 4 && k == 3) {
        puts("-1");
        return;
    }
    m = 0;
    while ((1 << m) < n) {
        ++m;
    }
    for (int i = 0; i < n; ++i) {
        par[i] = n - 1 - i;
        par[n - 1 - i] = i;
    }
    for (int i = m - 1; i >= 0; --i) {
        if ((k >> i) & 1) {
            swap(par[0], par[1 << i]);
            swap(par[par[0]], par[par[1 << i]]);
        }
    }
    int check = 0;
    for (int i = 0; i < n; ++i) {
        if (par[i] > i) {
            printf("%d %d\n", i, par[i]);
            check += (i & par[i]);
        }
    }
    //printf("%d\n", check);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}