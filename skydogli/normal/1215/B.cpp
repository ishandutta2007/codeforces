#include<bits/stdc++.h>
using namespace std;
#define MN 200005
int a1,a2,k1,k2,n,tag[MN];
long long s0,s1,sum[2];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int a;
		scanf("%d",&a);
		if(a<0)tag[i]=1;
		//s1++;
//			else s0++;
	}
	int now=1;
	for(int i=1;i<=n;++i){
		now^=tag[i];
		if(tag[i]) {swap(sum[0],sum[1]);sum[0]++;}
			else sum[1]++;
//		cout<<"HI "<<i<<" "<<now<<endl;
//		sum[now]++;
		s0+=sum[1];
		s1+=sum[0];
	}
	printf("%I64d %I64d",s1,s0);
}