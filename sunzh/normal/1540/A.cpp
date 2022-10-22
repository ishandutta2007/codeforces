#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
typedef long long ll;
int T,n,d[100010];
int main(){
	T=read();
	while(T--){
		n=read();for(int i=1;i<=n;++i) d[i]=read();
		ll ans=0;
		int mx=0;
		for(int i=1;i<=n;++i) mx=max(mx,d[i]);
		ans=mx;sort(d+1,d+n+1);
		for(int i=1;i<=n;++i) ans+=1ll*(n-i)*d[i]-1ll*(i-1)*d[i];
		printf("%lld\n",ans);
	}
}