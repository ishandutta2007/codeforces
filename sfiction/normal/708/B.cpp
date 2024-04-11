#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

int main(){
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int n = 1, m = 1;
	for (; n * (n - 1) / 2 < a; ++n);
	for (; m * (m - 1) / 2 < d; ++m);
	(n < m ? n : m) -= b == 0 && c == 0;
	if (n * (n - 1) / 2 - a || m * (m - 1) / 2 - d || n * m - b - c)
		puts("Impossible");
	else{
		for (int i = n + m; i--; )
			if (b >= m)
				putchar('0'), b -= m;
			else
				putchar('1'), --m;
	}
	return 0;
}