#include <stdio.h>
#include <string.h>
inline int read()
{
	int num = 0; char c = getchar();
	while (c < 48 || c > 57)c = getchar();
	while (c >= 48 && c <= 57)num = (num << 3) + (num << 1) + (c ^ 48), c = getchar();
	return num;
}
char _F[33];
inline void print(long long x) {
	if (x == 0)
	{
		putchar(48);
		return;
	}
	long long tmp = x > 0 ? x : ~x + 1;
	if (x < 0) putchar('-');
	int cnt = 0;
	while (tmp) {
		_F[cnt++] = tmp % 10 + '0';
		tmp /= 10;
	}
	while (cnt > 0) putchar(_F[--cnt]);
}
int a[10086], f[10086], c[10086], s[10086];
int main() {
	int n = read(), m = read(), ans = 0x3f3f3f3f, sum;
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 0; i <= 1086; f[1] = ++i, c[1] = f[1] - a[1], sum = (c[1] ? 1 : 0))
	{
		if (!i)continue;
		for (int j = 2; j <= n; j++) f[j] = f[j - 1] + m, c[j] = f[j] - a[j], sum += (c[j] ? 1 : 0);
		if (ans > sum)
		{
			memcpy(s, c, sizeof(int)*(n + 2));
			ans = sum;
		}
	}
	print(ans); putchar(10);//A fhdsiuhfsdi ifdasd 
	for (int i = 1; i <= n; i++)
	{
		if (!s[i]) continue;
		if (s[i] > 0) putchar('+'), putchar(32), print(i), putchar(32), print(s[i]), putchar(10);
		else putchar('-'), putchar(32), print(i), putchar(32), print(-s[i]), putchar(10);
	}
	return 0;
}