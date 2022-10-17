#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,num[100],cnt[200010];
LL a[200010];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		LL temp=a[i];
		while(temp&&(!(temp&1))){
			cnt[i]++;
			temp>>=1;
		}
		num[cnt[i]]++;
	}
	int id=0;
	for(int i=1;i<=63;i++){
		if(num[i]>num[id]){
			id=i;
		}
	}
	printf("%d\n",n-num[id]);
	for(int i=1;i<=n;i++){
		if(cnt[i]!=id){
			printf("%I64d ",a[i]);
		}
	}
	puts("");
	return 0;
}