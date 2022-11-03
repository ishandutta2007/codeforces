#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 1E5 + 10;

bool row[MAXN], col[MAXN];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	ll a = n, b = n;
	for (int x, y, i = 0; i < m; ++i){
		scanf("%d%d", &x, &y);
		a -= !(row[x]++);
		b -= !(col[y]++);
		printf("%I64d%c", a * b, "\n "[i + 1 < m]);
	}
	return 0;
}