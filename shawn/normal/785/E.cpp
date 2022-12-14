#include <bits/stdc++.h>

using namespace std;

#define For(i, j, k) for (int i = j; i <= k; i ++)

int read() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

void write(long long x) {
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

const int maxn = 2e5 + 10;
int Bit[450][maxn], L[maxn], R[maxn], a[maxn], b[maxn];
int n, m, l, r, siz;
long long ans;
namespace BIT {
	int S(int *bit, int x) {
		int ret = 0;
		for (int i = x; i; i -= i & -i) ret += bit[i];
		return ret;
	}
	void A(int *bit, int x, int y) {
		for (int i = x; i <= n; i += i & -i) bit[i] += y;
	}
}

int main() {
	n = read(), m = read();
	For(i, 1, n) a[i] = i;
	siz = sqrt(n);
	For(i, 1, n) b[i] = (i + siz - 1) / siz;
	For(i, 1, b[n]) L[i] = (i - 1) * siz + 1, R[i] = i * siz; R[b[n]] = n;
	For(i, 1, n) BIT::A(Bit[b[i]], a[i], 1);
	while(m--) {
		l = read(), r = read();
		//calc
		if (l > r) swap(l, r);
		if (a[l] < a[r]) ans++;
		if (a[l] > a[r]) ans--;
		if (b[l + 1] + 1 <= b[r - 1] - 1) {
			int st = b[l + 1] + 1;
			int ed = b[r - 1] - 1;
			For(i, st, ed) {
				ans += BIT::S(Bit[i], a[r] - 1);
				ans += (siz - BIT::S(Bit[i], a[l]));
				ans -= (siz - BIT::S(Bit[i], a[r]));
				ans -= BIT::S(Bit[i], a[l] - 1);
			}
			For(i, l + 1, L[st] - 1) 
				ans += (a[l] < a[i]) ? 1 : -1,
				ans += (a[i] < a[r]) ? 1 : -1;
			For(i, R[ed] + 1, r - 1) 
				ans += (a[l] < a[i]) ? 1 : -1,
				ans += (a[i] < a[r]) ? 1 : -1;
		}
		else {
			For(i, l + 1, r - 1) ans += (a[l] < a[i]) ? 1 : -1;
			For(i, l + 1, r - 1) ans += (a[i] < a[r]) ? 1 : -1;
		}
		write(ans), putchar(10);
		// update
		BIT::A(Bit[b[l]], a[l], -1);
		BIT::A(Bit[b[r]], a[r], -1);
		BIT::A(Bit[b[l]], a[r], 1);
		BIT::A(Bit[b[r]], a[l], 1);
		swap(a[l], a[r]);
	}
	return 0;	
}