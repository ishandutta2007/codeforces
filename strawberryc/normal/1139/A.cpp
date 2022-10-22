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

//

typedef long long ll;

const int N = 1e5 + 5;

int n;
char s[N];
ll ans;

int main()
{
	n = read();
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
		if (s[i] - '0' + 1 & 1) ans += i;
	std::cout << ans << std::endl;
	return 0;
}