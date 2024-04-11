#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#define int long long
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
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,k;
int a[100010];
int cnt[100010];
priority_queue<PII> Q;
long long getsum(int x,int k){
	int t=a[x]/k;
	int p=a[x]%k;
	return 1ll*t*t*(k-p)+1ll*(t+1)*(t+1)*p;
}
signed main(){
	n=read(),k=read();
	unsigned long long ans=0;
	for(int i=1;i<=n;++i) a[i]=read(),ans+=1ll*a[i]*a[i];
//	printf("%llu\n",ans);
	k-=n;
	for(int i=1;i<=n;++i){
		Q.push(mp(getsum(i,1)-getsum(i,2),i));
	}
	while(k--){
		PII u=Q.top();Q.pop();
//		printf("%d\n",u.fi);
		ans-=u.fi;
		++cnt[u.se];
		if(cnt[u.se]==a[u.se]-1) continue ;
		u.fi=getsum(u.se,cnt[u.se]+1)-getsum(u.se,cnt[u.se]+2);
		Q.push(u);
	}
	printf("%llu\n",ans);
}