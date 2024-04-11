#include <bits/stdc++.h>

// 20030830

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

typedef long long ll;

const int N = 3e5 + 5;

int n, m, stk[N], top;
ll rsid, suml, sums, sumb, X[N], Y[N], offset, firs;
bool le0 = 1, ri0 = 1;

bool check(int i, int j, int k)
{
	return 1.0 * (Y[i] - Y[j]) / (X[i] - X[j]) <=
		1.0 * (Y[j] - Y[k]) / (X[j] - X[k]);
}

ll calc(int i)
{
	return Y[i] - X[i] * sums;
}

int main()
{
	int op, x, y;
	rsid = read(); m = read();
	while (m--)
	{
		op = read(); x = read();
		if (op == 1) offset += x, le0 = 1;
		else if (op == 2) rsid += x, ri0 = 1;
		else
		{
			if (le0) firs = x;
			else firs += x;
			y = read();
			if (ri0)
			{
				X[++n] = suml; Y[n] = suml * sums + sumb;
				while (top > 1 && check(stk[top - 1], stk[top], n)) top--;
				stk[++top] = n;
				suml = rsid; sums += y; sumb += offset * y + x;
				while (top > 1 && calc(stk[top]) <= calc(stk[top - 1])) top--;
			}
			else
			{
				sums += y; sumb += offset * y + x;
				while (top > 1 && calc(stk[top]) <= calc(stk[top - 1])) top--;
			}
			le0 = ri0 = 0;
		}
		if (le0) {puts("1 0"); continue;}
		if (ri0) {printf("%lld 0\n", offset + suml + 1); continue;}
		ll pos = offset + X[stk[top]] + 1, val = sumb - calc(stk[top]);
		if (firs <= val) pos = 1, val = firs;
		printf("%lld %lld\n", pos, val);
	}
	return 0;
}