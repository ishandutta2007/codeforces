#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000005];
long long cnt[3000005],val[3000005];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		cnt[a[i]]++;
	}
	for(int i=1;i<=3000000;i++){
		for(int j=1;i*j<=3000000;j++){
			val[i*j]+=1ll*cnt[i]*(cnt[j]-(i==j));
		}
	}
	for(int i=1;i<=3000000;i++){
		val[i]+=val[i-1];
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int x;
		scanf("%d",&x);
		printf("%lld\n",1ll*n*(n-1)-val[x-1]);
	}
	return 0;
}