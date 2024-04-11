#include<bits/stdc++.h>

using namespace std;

int power(int a, int b, int m, int ans=1) {
	for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	
	if(n == 1) return puts("YES\n1"), 0;
	if(n == 4) return puts("YES\n1 3 2 4"), 0;
	
	for(int i=2; i<n; i++) if(n % i == 0) return puts("NO"), 0;
	
	puts("YES");
	puts("1");
	for(int i=2; i<=n-1; i++) {
		printf("%d\n", (long long) i * power(i-1, n-2, n) % n);
	}
	cout<<n<<endl;
}