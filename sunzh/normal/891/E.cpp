#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<unordered_map>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,k;
const int mod=1e9+7;
int a[5010];
int c[5010],t[5010];
int qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;k>>=1;
	}
	return res;
}
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i) a[i]=read();
	c[0]=1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<i;++j){
			t[j]=c[j];
		}
		for(int j=0;j<=i;++j){
			c[j]=(1ll*t[j]*a[i]%mod-t[j-1]+mod)%mod;
		}
	}
	int ans=0;
	for(int i=0;i<=n&&i<=k;++i){
		int res=qpow(n,k-i);
		for(int j=0;j<i;++j){
			res=1ll*res*(k-j)%mod;
		}
		res=1ll*res*c[i]%mod;
		(ans+=res)%=mod;
	}
	printf("%d\n",(c[0]-1ll*ans*qpow(qpow(n,k),mod-2)%mod+mod)%mod);
}