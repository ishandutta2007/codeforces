#include <stdio.h>
#include <algorithm>
#define N 100100

using namespace std;

typedef __int64 ll;
ll s1, s2;
int a[N];

ll gcd(ll a, ll b) {
	if (!b) return a;
	return gcd(b, a%b);
}

int main() {
	int n, i, m;
	ll x;
//	freopen ("in.txt", "r", stdin);
//	freopen ("in.txt", "r", stdin);
	scanf("%d", &n);
	m=1-n;
	s1=s2=0;
	for (i=0; i<n; i++) scanf("%d", a+i), s2+=a[i];
	sort(a, a+n);
	for (i=0; i<n; i++) {
		s1+=(ll)a[i]*m;
		m+=2;
	}
	s1=s1*2+s2;
	x=gcd(s1, (ll)n);
	printf("%I64d %I64d\n", s1/x, (ll)n/x);
	return 0;
}