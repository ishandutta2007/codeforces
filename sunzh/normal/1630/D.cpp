#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
int n,m;
int a[1000010],b[1000010];
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;++i) a[i]=read();
		for(int i=1;i<=m;++i) b[i]=read();
		int gcd=b[1];
		for(int i=2;i<=m;++i) gcd=__gcd(gcd,b[i]);
		long long ans0=0,ans1=0;
		for(int i=1;i<=gcd;++i){
			long long res=0;
			long long mn=1e18;
			int cnt=0;
			for(int j=i;j<=n;j+=gcd){
				res+=llabs(a[j]);
				mn=min(mn,llabs(a[j]));
				cnt^=(a[j]<0);
			}
			// printf("%d %d\n",cnt,res);
			if(cnt) ans1+=res,ans0+=res-2*mn;
			else ans0+=res,ans1+=res-2*mn;
		}
		printf("%lld\n",max(ans0,ans1));
	}
}