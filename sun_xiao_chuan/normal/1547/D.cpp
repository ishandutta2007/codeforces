#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t,m,a[200500],b[200500],sb,sb2;
#define b(x) (1<<((x)-1))

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		printf("0 ");
		for(i=2;i<=n;i++){
			sb=(a[i-1]^b[i-1]);
			sb2=(sb|a[i]);
			sb2^=a[i];
			b[i]=sb2;
			printf("%d ",b[i]);
		}
		puts("");
	}
}