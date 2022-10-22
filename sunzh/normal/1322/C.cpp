#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<random>
#include<ctime>
#define PII pair<int,int>
#define mp make_pair
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int T;
int n,m;
int c[500010];
int rnd1[500010],rnd2[500010];
mt19937 rd(time(NULL));
int sum[500010];
int hsh1[500010],hsh2[500010];
map<PII,int>ps;
signed main(){
	T=read();
	while(T--){
		int cnt=0;
		ps.clear();
		n=read(),m=read();
		for(int i=1;i<=n;++i) c[i]=sum[i]=hsh1[i]=hsh2[i]=0,rnd1[i]=rd(),rnd2[i]=rd();
		for(int i=1;i<=n;++i) c[i]=read();
		for(int i=1;i<=m;++i){
			int u=read(),v=read();
			hsh1[v]^=rnd1[u];hsh2[v]+=rnd2[u];
		}
		for(int i=1;i<=n;++i){
			if(hsh1[i]==0&&hsh2[i]==0) continue ;
			PII k=mp(hsh1[i],hsh2[i]);
			if(ps.count(k)) sum[ps[k]]+=c[i];
			else sum[ps[k]=++cnt]=c[i];
		}
		int ans=sum[1];
		for(int i=2;i<=cnt;++i) ans=__gcd(ans,sum[i]);
		printf("%lld\n",ans);
	}
	return 0;
}