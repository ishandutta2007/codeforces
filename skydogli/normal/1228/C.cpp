#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define int long long
#define Mod 1000000007
int x;
LL res=1,n;
LL ksm(LL a,LL x){
	LL w=a,ans=1;
	while(x){
		if(x&1)ans=ans*w%Mod;
		w=w*w%Mod;
		x>>=1;
	}
	return ans;
}
signed main(){
	scanf("%I64d%I64d",&x,&n);
	for(int i=2;i*i<=x&&i<=n;++i){
	//	cout<<"HI "<<i<<endl;
		if(x%i==0){
			while(x%i==0)x/=i;
			LL tmp=i;
			while(tmp<=n){
				res=res*ksm(i,(n/tmp))%Mod;
				if(n/i<tmp)break;
				tmp*=i;
			}
		}
	}
	if(x!=1){
			LL tmp=x;
			while(tmp<=n){
				res=res*ksm(x,(n/tmp))%Mod;
				if(n/x<tmp)break;
				tmp*=x;
			}
	}
	printf("%I64d",res);
	return 0;
}