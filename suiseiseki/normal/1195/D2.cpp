#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 100000
#define ll long long
#define Mod 998244353
ll a[Maxn+5];
struct Number{
	int a[15];
	int len;
	friend bool operator <(Number p,Number q){
		return p.len>q.len;
	}
}num[Maxn+5];
int l_n[20];
ll d[25];
int main(){
	int n;
	scanf("%d",&n);
	d[1]=1;
	for(int i=2;i<=21;i++){
		d[i]=d[i-1]*10;
		d[i]%=Mod;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(ll j=1,k=1;j<=a[i];j*=10,k++){
			num[i].a[k]=a[i]/j%10;
			if(j*10>a[i]){
				num[i].len=k;
			}
		}
		l_n[num[i].len]++;
	}
	sort(num+1,num+1+n);
	ll now=0;
	ll ans=0;
	for(int i=1;i<=n;i++){
		now=0;
		for(int j=num[i].len;j<=num[1].len;j++){
			now+=l_n[j];
		}
		for(int j=1;j<=num[i].len;j++){
			ans+=num[i].a[j]*d[(j<<1)-1]%Mod*now%Mod;
			ans%=Mod;
			ans+=num[i].a[j]*d[j<<1]%Mod*now%Mod;
			ans%=Mod;
		}
		for(int j=num[i].len-1;j>0;j--){
			for(int k=num[i].len;k>j;k--){
				ans+=num[i].a[k]*d[(j<<1)+k-j]%Mod*l_n[j]%Mod*2%Mod;
				ans%=Mod;
			}
			for(int k=1;k<=j;k++){
				ans+=num[i].a[k]*d[(k<<1)-1]%Mod*l_n[j]%Mod;
				ans%=Mod;
				ans+=num[i].a[k]*d[k<<1]%Mod*l_n[j]%Mod;
				ans%=Mod;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}