#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

int main(){
	int n, k;
	double l, v1, v2, v3;
	scanf("%d%lf%lf%lf%d", &n, &l, &v1, &v2, &k);
	n = (n - 1) / k + 1;
	v3 = (v1 + v2) / 2.0;
	double l2 = v3 / (v1 * (n - 1) + v3) * l;
	double l1 = l - l2;
	printf("%.10f\n", l1 / v1 + l2 / v2);
	return 0;
}