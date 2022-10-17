#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define ll unsigned long long
#define Mod 1000000007
ll n;
int m;
ll f[10005][60];
ll inv[65];
ll solve(ll x,int y){
	memset(f,0,sizeof f);
	f[0][y]=1;
	for(int i=0;i<m;i++){
		for(int j=0;j<=y;j++){
			if(f[i][j]>0){
				for(int k=0;k<=j;k++){
					f[i+1][k]=(f[i+1][k]+f[i][j]*inv[j+1])%Mod;
				}
			}
		}
	}
	ll sum=0,now=1;
	for(int i=0;i<=y;i++){
		sum=(sum+now*f[m][i])%Mod;
		now=(now*x)%Mod;
	}
	return sum;
}
int main(){
	cin>>n;
	scanf("%d",&m);
	inv[1]=1;
	for(int i=2;i<=60;i++){
		inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
	}
	ll ans=1;
	int cnt;
	for(int i=2;(ll)i*i<=n;i++){
		if(n%i==0){
			cnt=0;
			while(n%i==0){
				cnt++;
				n/=i;
			}
			ans*=solve(i,cnt);
			ans%=Mod;
		}
	}
	if(n>1){
		ans*=solve(n,1);
		ans%=Mod;
	}
	cout<<ans<<endl;
	return 0;
}