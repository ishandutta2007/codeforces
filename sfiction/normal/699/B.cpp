#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 1E3 + 10;

char s[MAXN][MAXN];
int row[MAXN], col[MAXN];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int tot = 0;
	for (int i = 0; i < n; ++i){
		scanf("%s", s[i]);
		for (int j = 0; j < m; ++j){
			tot += s[i][j] == '*';
			if (s[i][j] == '*')
				++row[i], ++col[j];
		}
	}
	int a = -1, b = -1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (row[i] + col[j] - (s[i][j] == '*') == tot)
				a = i, b = j;
	if (~a)
		printf("YES\n%d %d\n", a + 1,  b + 1);
	else
		puts("NO");
	return 0;
}