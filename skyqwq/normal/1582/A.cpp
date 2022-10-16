// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
int a, b, c;

int main() {
	int T; read(T);
	while (T--) {
		read(a), read(b), read(c);
		LL s = (a + b * 2ll + 3ll * c) & 1;
		if (s & 1) {
			if (a || b) puts("1");
			else puts("3");
		} else {
			if (a) puts("0");
			else {
				if (b >= 3 || b % 2 == 0) puts("0");
				else puts("2");
			}
		}
	}
    return 0;
}