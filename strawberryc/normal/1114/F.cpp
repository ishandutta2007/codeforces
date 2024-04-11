#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define p2 p << 1
#define p3 p << 1 | 1

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

inline char get()
{
	char c;
	while ((c = getchar()) != 'M' && c != 'T');
	return c;
}

typedef long long ll;

const int N = 4e5 + 5, M = N << 2, C = (1 << 16) + 5, E = 305, ZZQ = 1e9 + 7;

int n, q, a[N], tot, pri[E], phi[E], phis[M], prod[M], phid[4][C],
dihp[4][C], inv[E];
bool mark[E];
ll prm[M], pmul[M], fac[E];

int qpow(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = 1ll * res * a % ZZQ;
		a = 1ll * a * a % ZZQ;
		b >>= 1;
	}
	return res;
}

void sieve()
{
	mark[0] = mark[phi[1] = 1] = 1;
	for (int i = 2; i <= 300; i++)
	{
		if (!mark[i]) phi[pri[++tot] = i] = i - 1, fac[i] = 1ll << tot - 1;
		for (int j = 1; j <= tot; j++)
		{
			if (1ll * i * pri[j] > 300) break;
			mark[i * pri[j]] = 1;
			fac[i * pri[j]] = fac[i] | (1ll << j - 1);
			if (i % pri[j] == 0)
			{
				phi[i * pri[j]] = phi[i] * pri[j];
				break;
			}
			else phi[i * pri[j]] = phi[i] * (pri[j] - 1);
		}
	}
	inv[1] = 1;
	for (int i = 2; i <= 300; i++)
		inv[i] = 1ll * (ZZQ - ZZQ / i) * inv[ZZQ % i] % ZZQ;
	for (int i = 0; i < 4; i++)
		for (int S = 0; S < (1 << 16); S++)
		{
			phid[i][S] = dihp[i][S] = 1;
			for (int j = 0; j < 16; j++)
				if ((S >> j) & 1)
					phid[i][S] = 1ll * phid[i][S] * pri[i * 16 + j + 1] % ZZQ
						* inv[pri[i * 16 + j + 1] - 1] % ZZQ,
					dihp[i][S] = 1ll * dihp[i][S] * inv[pri[i * 16 + j + 1]] % ZZQ
						* (pri[i * 16 + j + 1] - 1) % ZZQ;
		}
}

int get_phid(ll S)
{
	return 1ll * phid[0][S & 65535] * phid[1][(S >> 16) & 65535] % ZZQ
		* phid[2][(S >> 32) & 65535] % ZZQ * phid[3][S >> 48] % ZZQ;
}

int get_dihp(ll S)
{
	return 1ll * dihp[0][S & 65535] * dihp[1][(S >> 16) & 65535] % ZZQ
		* dihp[2][(S >> 32) & 65535] % ZZQ * dihp[3][S >> 48] % ZZQ;
}

int getphi(int a, int n, ll S)
{
	return 1ll * qpow(a, n) * get_dihp(S) % ZZQ;
}

int mulphi(int a, int b, ll A, ll B)
{
	return 1ll * a * b % ZZQ * get_phid(A & B) % ZZQ;
}

void down(int p)
{
	prod[p2] = 1ll * prod[p2] * prod[p] % ZZQ;
	prod[p3] = 1ll * prod[p3] * prod[p] % ZZQ;
	prod[p] = 1;
	pmul[p2] |= pmul[p]; pmul[p3] |= pmul[p]; pmul[p] = 0;
}

void upt(int l, int r, int p)
{
	int mid = l + r >> 1;
	prm[p] = prm[p2] | pmul[p2] | prm[p3] | pmul[p3];
	phis[p] = mulphi(mulphi(phis[p2], getphi(prod[p2], mid - l + 1, pmul[p2]),
		prm[p2], pmul[p2]), mulphi(phis[p3], getphi(prod[p3], r - mid, pmul[p3]),
		prm[p3], pmul[p3]), prm[p2] | pmul[p2], prm[p3] | pmul[p3]);
}

void build(int l, int r, int p)
{
	if (l == r)
	{
		prm[p] = fac[a[l]];
		phis[p] = phi[a[l]];
		return (void) (prod[p] = 1, pmul[p] = 0);
	}
	int mid = l + r >> 1;
	build(l, mid, p2); build(mid + 1, r, p3);
	upt(l, r, p);
	prod[p] = 1; pmul[p] = 0;
}

void change(int l, int r, int s, int e, int v, int p)
{
	if (l == s && r == e)
	{
		prod[p] = 1ll * prod[p] * v % ZZQ;
		pmul[p] |= fac[v];
		return;
	}
	int mid = l + r >> 1; down(p);
	if (e <= mid) change(l, mid, s, e, v, p2);
	else if (s > mid) change(mid + 1, r, s, e, v, p3);
	else change(l, mid, s, mid, v, p2),
		change(mid + 1, r, mid + 1, e, v, p3);
	upt(l, r, p);
}

struct node
{
	int phi; ll S;
	
	friend inline node operator * (node a, node b)
	{
		return (node) {1ll * a.phi * b.phi % ZZQ * get_phid(a.S & b.S) % ZZQ,
			a.S | b.S};
	}
};

node ask(int l, int r, int s, int e, int p)
{
	if (l == s && r == e) return ((node) {phis[p], prm[p]})
		* ((node) {getphi(prod[p], r - l + 1, pmul[p]), pmul[p]});
	int mid = l + r >> 1; down(p); node res;
	if (e <= mid) res = ask(l, mid, s, e, p2);
	else if (s > mid) res = ask(mid + 1, r, s, e, p3);
	else res = ask(l, mid, s, mid, p2) * ask(mid + 1, r, mid + 1, e, p3);
	return upt(l, r, p), res;
}

int main()
{
	char op;
	int l, r, x;
	sieve();
	n = read(); q = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	build(1, n, 1);
	while (q--)
	{
		op = get(); l = read(); r = read();
		if (op == 'M') x = read(), change(1, n, l, r, x, 1);
		else printf("%d\n", ask(1, n, l, r, 1).phi);
	}
	return 0;
}