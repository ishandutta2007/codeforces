#include <bits/stdc++.h>
using namespace std;
const int N=200000+10;
int t,n,a[N];
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int mx=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			mx=max(mx,a[i]);
		}
		int cnt=0;
		for(int i=1;i<=n;i++)if(a[i]==mx)cnt++;
		if(cnt==n){
			printf("%d\n",n);
		}else{
			printf("1\n");
		}
	}
}