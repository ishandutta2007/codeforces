#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,n,a[N];
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		bool ok=0;
		for(int i=1;i<=n;i++)if(a[i]!=a[1])ok=1;
		if(!ok){
			printf("NO\n");
		}else{
			printf("YES\n");
			int rt=-1;
			for(int i=2;i<=n;i++){
				if(a[i]!=a[1]){
					printf("%d %d\n", 1,i); rt=i;
				}
			}
			for(int i=2;i<=n;i++){
				if(a[i]==a[1]){
					printf("%d %d\n", rt,i);
				}
			}
		}
	}
}