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

PII a[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		scanf("%d", &a[i].st);
		a[i].nd = i + 1;
	}
	sort(a, a + n);
	for (int i = 0, j = n - 1; i < j; ++i, --j)
		printf("%d %d\n", a[i].nd, a[j].nd);
	return 0;
}