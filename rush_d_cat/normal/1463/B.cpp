#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int a[N],b[N];
int main() {
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);

		LL sum=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]); 
			sum += a[i];
		}

		LL s=0;
		for(int i=1;i<=n;i++){
			if(i%2==1) s+=a[i]-1;
		}
		if(s*2 <= sum) {
			for(int i=1;i<=n;i++){
				if(i%2)printf("%d ", 1); else printf("%d ", a[i]);
			}
			printf("\n");
		}else{
			for(int i=1;i<=n;i++){
				if(i%2==0)printf("%d ", 1); else printf("%d ", a[i]);
			}
			printf("\n");
		}
	}	
}