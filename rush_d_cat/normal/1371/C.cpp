#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t;
LL a,b,n,m;
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%lld%lld%lld%lld",&a,&b,&n,&m);
		bool ok=1;
		if(min(a,b)<m) ok=0;
		else{
			a-=m; 
			if(a+b<n) ok=0;
		}
		printf("%s\n", ok?"Yes":"No");
	}
}