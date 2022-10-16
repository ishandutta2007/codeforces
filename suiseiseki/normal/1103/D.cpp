#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 1000000
#define ll long long
#define Maxk 12
#define Inf 0x3f3f3f3f3f3f3f3fll
template<typename Elem>
void read(Elem &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
map<ll,int> mp;
int n;
ll k;
struct Node{
	ll a;
	int e;
	friend bool operator <(Node p,Node q){
		return p.e<q.e;
	}
}a[Maxn+5];
ll gcd(ll a,ll b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
ll mn(ll a,ll b){
	return a<b?a:b;
}
ll p[Maxk+5];
int len;
void work(ll x,ll *a){
	len=0;
	for(ll i=2;i*i<=x;i++){
		if(x%i==0){
			a[++len]=i;
			while(x%i==0){
				x/=i;
			}
		}
	}
	if(x>1){
		a[++len]=x;
	}
}
ll f[2][Maxk+5][(1<<Maxk)|5];
ll num[(1<<Maxk)|5];
int vis[(1<<Maxk)|5];
int main(){
	read(n),read(k);
	ll g=0;
	for(int i=1;i<=n;i++){
		read(a[i].a);
		g=gcd(a[i].a,g);
	}
	if(g==1){
		puts("0");
		return 0;
	}
	work(g,p);
	for(int i=1;i<=n;i++){
		read(a[i].e);
	}
	sort(a+1,a+1+n);
	memset(f[1],0x3f,sizeof f[1]);
	f[1][0][0]=0;
	for(int i=1;i<=n;i++){
		ll now=1;
		for(int j=1;j<=len;j++){
			ll tmp=1;
			while(a[i].a%p[j]==0){
				a[i].a/=p[j];
				tmp*=p[j];
			}
			now*=tmp;
			num[1<<(j-1)]=tmp;
		}
		if(mp[now]>=len){
			continue;
		}
		mp[now]++;
		memcpy(f[0],f[1],sizeof f[0]);
		num[0]=1;
		for(int j=1;j<(1<<len);j++){
			num[j]=num[j^(j&(-j))]*num[j&(-j)];
			if(vis[j]<=len){
//				vis[j]++;
			}
		}
		for(int l=0;l<len;l++){
			for(int j=1;j<(1<<len);j++){
				if(num[j]>k){
					continue;
				}
				if(vis[j]>len){
					continue;
				}
				int mask=(~j)&((1<<len)-1);
				for(int k=mask;k;k=(k-1)&mask){
					f[1][l+1][k|j]=mn(f[1][l+1][k|j],f[0][l][k]+a[i].e);
				}
				f[1][l+1][j]=mn(f[1][l+1][j],f[0][l][0]+a[i].e);
			}
		}
	}
	ll ans=Inf;
	for(int i=1;i<=len;i++){
		if(f[1][i][(1<<len)-1]!=Inf){
			ans=mn(ans,f[1][i][(1<<len)-1]*i);
		}
	}
	cout<<(ans==Inf?-1:ans)<<endl;
	return 0;
}