#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 100000
#define ll long long
#define Mod 998244353
ll a[Maxn+5][15];
ll d[25];
int main(){
	int n;
	scanf("%d",&n);
	d[1]=1;
	for(int i=2;i<=21;i++){
		d[i]=d[i-1]*10;
		d[i]%=Mod;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
		for(ll j=1,k=1;j<=a[i][0];j*=10,k++){
			a[i][k]=a[i][0]/j%10;
		}
	}
	int len=0;
	ll now;
	now=a[1][0];
	while(now){
		len++;
		now/=10;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=len;j++){
			ans+=a[i][j]*d[(j<<1)-1]%Mod*n%Mod;
			ans%=Mod;
			ans+=a[i][j]*d[j<<1]%Mod*n%Mod;
			ans%=Mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}