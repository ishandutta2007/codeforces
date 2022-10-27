#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, q;
int a[N]; LL s[N], fac[N];

int main() {
	fac[0]=1;
	for(int i=1;i<18;i++){
		fac[i]=fac[i-1]*i;
	}
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) {
		a[i]=i; s[i]=s[i-1]+a[i];
	}
	LL k=1;
	while(q--) {
		int op,l,r,x;
		scanf("%d",&op);
		if(op==1) {
			scanf("%d%d",&l,&r);
			printf("%lld\n", s[r] - s[l-1]);
		}else{
			scanf("%d",&x); k+=x;
			int pos=max(n-15,1);
			LL all=k;
			vector<int> vec;
			for(int i=pos;i<=n;i++){
				vec.push_back(i);
			}
			for(int i=pos;i<=n;i++){
				LL ways=fac[n-i];
				//printf("ways=%lld\n", ways);
				LL idx=(all+ways-1)/ways - 1;
				for(int j=0;j<vec.size();j++){
					if(j==idx) {
						a[i]=vec[j]; s[i]=s[i-1]+a[i];
						vector<int> foo;
						for(int k=0;k<vec.size();k++)if(k!=j)
							foo.push_back(vec[k]);
						all -= j * ways;
						vec=foo;
						break;
					}
				}
			}
		}
	}	
}