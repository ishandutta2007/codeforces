// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 55;


int n, m;

char a[N], b[N];

int main() {
 	int T; read(T);
 	while (T--) {
 		read(n), read(m);
 		scanf("%s%s", a + 1, b + 1);
 		bool ok = 1;
 		for (int i = 2; i <= m; i++)
 			ok &= b[i] == a[n - (m - i + 1) + 1];
 		bool op = 0;
 		for (int i = 1; i <= n - m + 1; i ++)
 			if (b[1] == a[i]) op = 1;
 		ok &= op;
 		puts(ok ? "YES" : "NO");
 	}   
    return 0;
}