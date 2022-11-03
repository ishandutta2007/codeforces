#include <bits/stdc++.h>
using namespace std;

const int Mod=998244353;

int ksmii(int a,int b){
	if(!b){
		return 1;
	}
	int x=ksmii(a,b>>1);
	x=1ll*x*x%Mod;
	if(b&1){
		x=1ll*a*x%Mod;
	}
	return x;
}

//Length: k
//All: n(n-1)^(k-1)
//OneSame: (n-1)^k
//TwoSame: dp[k-2]
//dp[k]: All-2*OneSame-TwoSame

int dp[200005],dp2[200005];
int n,k;
int ts[200005],og[200005];

int main(){
	scanf("%d%d",&n,&k);
	dp[0]=dp2[0]=1;
	dp[1]=k-2;
	dp2[1]=k-1;
	for(int i=2;i<=n;i++){
		int val=ksmii(k-1,i-1);
		dp[i]=(dp2[i-1]+1ll*dp[i-1]*(k-2))%Mod;
		dp2[i]=1ll*dp[i-1]*(k-1)%Mod;
	}
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if(i%2){
			ts[i/2+1]=x;
		}else{
			og[i/2]=x;
		}
	}
	int Ans=1;
	//Chooly Ts
	{
		int ans=1;
		int now=1;
		int tss=(n+1)/2;
		for(;now<=tss&&ts[now]==-1;now++){
			ans=1ll*ans*(k-1)%Mod;
		}
		if(now>tss){
			ans=1ll*ksmii(k-1,tss-1)*k%Mod;
			Ans=1ll*Ans*ans%Mod;
			goto Shi;
		}
		while(1){
			int ff=0;
			while(now<=tss&&ts[now]!=-1){
				if(ff==ts[now]){
					puts("0");
					return 0;
				}
				ff=ts[now];
				now++;
			}
			if(now>tss){
				break;
			}
			int cntt=0;
			while(now<=tss&&ts[now]==-1){
				cntt++;
				now++;
			}
			if(now>tss){
				ans=1ll*ans*ksmii(k-1,cntt)%Mod;
				break;
			}
			if(ff==ts[now]){
				ans=1ll*ans*dp2[cntt]%Mod;
			}else{
				ans=1ll*ans*dp[cntt]%Mod;
			}
		}
		Ans=1ll*Ans*ans%Mod;
	}
	Shi:;
	//Chooly Og
	{
		int ans=1;
		int now=1;
		int ogs=n/2;
		for(;now<=ogs&&og[now]==-1;now++){
			ans=1ll*ans*(k-1)%Mod;
		}
		if(now>ogs){
			ans=1ll*ksmii(k-1,ogs-1)*k%Mod;
			Ans=1ll*Ans*ans%Mod;
			goto Shit;
		}
		while(1){
			int ff=0;
			while(now<=ogs&&og[now]!=-1){
				if(ff==og[now]){
					puts("0");
					return 0;
				}
				ff=og[now];
				now++;
			}
			if(now>ogs){
				break;
			}
			int cntt=0;
			while(now<=ogs&&og[now]==-1){
				cntt++;
				now++;
			}
			if(now>ogs){
				ans=1ll*ans*ksmii(k-1,cntt)%Mod;
				break;
			}
			if(ff==og[now]){
				ans=1ll*ans*dp2[cntt]%Mod;
			}else{
				ans=1ll*ans*dp[cntt]%Mod;
			}
		}
		Ans=1ll*Ans*ans%Mod;
	}
	Shit:;
	printf("%d\n",Ans);
	return 0;
}