#include<bits/stdc++.h>
using namespace std;
#define LL long long
int cnt1,cnt2,n;
long long b[200005];
int id[200005],sum[200005];
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%I64d",&b[i]);
		LL tmp=b[i];
		while(!(tmp&1ll))tmp/=2ll,id[i]++;
		sum[id[i]]++;
	}
	int ansid=0;
	for(int i=1;i<=62;++i)
		if(sum[ansid]<sum[i])ansid=i;
	printf("%d\n",n-sum[ansid]);
	for(int i=1;i<=n;++i)if(id[i]!=ansid)printf("%I64d ",b[i]);
	return 0;
}