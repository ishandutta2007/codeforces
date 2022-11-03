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

const int MAXN = 1E5 + 10;

int n;
int a[MAXN];
ll s[2][MAXN];

void update(ll s[], int i, int c){
	for (; i <= n; i = (i | i - 1) + 1)
		s[i] += c;
}

ll query(ll s[], int i){
	ll ret = 0;
	for (; i > 0; i &= i - 1)
		ret += s[i];
	return ret;
}

int main(){
	scanf("%d", &n);
	ll s0 = 0;
	double s1 = 0., s2 = 0.;
	for (ll i = 1; i <= n; ++i){
		scanf("%d", a + i);
		s0 += i - 1 - query(s[0], a[i]);
		ll t = query(s[1], a[i]);
		s1 += t * (n - i + 1);
		s2 += (i * (i - 1) / 2 - t) * (n - i + 1);
		update(s[0], a[i], 1), update(s[1], a[i], i);
	}
	printf("%.12f\n", s0 + (s1 - s2) / n / (n + 1));
	return 0;
}