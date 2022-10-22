#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n;
int a[100005];
signed main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
		sort(a+1,a+1+n);
		int mid=(n+1)/2;
		printf("%lld ",a[mid]);
		for(int i=1;i<=n;++i){
			int id=mid+i;
			if(id>n)break;
			printf("%lld ",a[id]);
			id=mid-i;
			if(id<1)break;
			printf("%lld ",a[id]);
		}
		puts("");
	}
	return 0;
}