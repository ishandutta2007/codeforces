#include<bits/stdc++.h>
#define rep(i,n) for(ll i=1;i<=n;++i)
#define N 100005
using namespace std;
typedef long long ll;
typedef long double ld;
ll p,k,now,ans[N],top=0;
int main(){
	scanf("%I64d%I64d",&p,&k);
	for(;p;)if(top&1){
		//printf("%lld\n",p);
		ans[++top]=k-p%k;
		if(p%k==0)ans[top]=0;
		p=(p-1)/k+1;
	}else{

		//printf("%lld\n",p);
		ans[++top]=p%k;
		p=p/k;
	}
	printf("%I64d\n",top);
	rep(i,top)printf("%I64d%c",ans[i],i==top?'\n':' ');
	//system("pause");
	return 0;
}
/*
x^2+92/x+214
(x-214)(x+214)-1926+92
*/