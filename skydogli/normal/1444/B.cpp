#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MN 300005
#define Mod 998244353
#define pii pair<int,int>
#define mp make_pair
int a[MN],T,n,m;
char ch[MN];
int gcd(int a,int b){if(!b)return a;return b;}
int ksm(int a,int x){
	int ans=1,w=a;
	while(x){
		if(x&1)ans=ans*w%Mod;
		w=w*w%Mod;
		x>>=1;
	}
	return ans;
}
signed main(){
	scanf("%lld",&n);
	n<<=1;
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n/2;++i){
		ans+=abs(a[i]-a[n-i+1]);
	}
	ans%=Mod;
	for(int i=n;i>n/2;--i){
		ans=ans*i%Mod;
		ans=ans*ksm(n-i+1,Mod-2)%Mod;
	}
	printf("%lld\n",ans);
	return 0;
}