#include <bits/stdc++.h>

typedef long long ll;

const int N = 1e5 + 5;

int a, q;
ll x[N], y[N];
char op[N];

void ADD(ll u, ll v) {x[++q] = u; y[q] = v; op[q] = '+';}

void XOR(ll u, ll v) {x[++q] = u; y[q] = v; op[q] = '^';}

void reduce()
{
	int tmp = a, cnt = 0, fin;
	while (tmp > 1) tmp >>= 1, cnt++;
	if (a == (1 << cnt + 1) - 1)
	{
		ADD(a, a); XOR(a << 1, a); ADD((a << 1) ^ a, a);
		ADD(a << 1, a << 1); XOR(a << 2, a << 1);
		XOR(1 << cnt + 2, (1 << cnt + 2) | 2); XOR(a, 2); a ^= 2;
		if (a == 1) return;
	}
	for (int i = 0; i <= cnt; i++) ADD(1ll * a << i, 1ll * a << i);
	ADD(1ll * a << cnt, a); XOR((1ll * a << cnt) + a, 1ll * a << cnt);
	ll now;
	XOR(now = (1ll * a << cnt) + a ^ (1ll * a << cnt), a); now ^= a;
	for (int i = cnt + 1; (now >> i) & 1; i++) fin = i;
	for (int i = fin; i >= cnt; i--)
		if ((now >> i) & 1) XOR(now, 1ll * a << i - cnt),
			now ^= 1ll * a << i - cnt;
	if (now & 1) return (void) (a = now);
	while ((a ^ now) >= (1ll << cnt)) ADD(now, now), now <<= 1;
	XOR(now, a); a ^= now;
}

int main()
{
	std::cin >> a;
	while (a > 1) reduce();
	std::cout << q << std::endl;
	for (int i = 1; i <= q; i++)
		printf("%lld %c %lld\n", x[i], op[i], y[i]);
	return 0;
}