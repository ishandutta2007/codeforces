#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
#define int long long
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
int a[7];
int n;
int b[100010];
struct node{
	int x,tp;
	bool operator <(const node &y)const{
		return x==y.x?tp<y.tp:x<y.x;
	}
}g[600010];
int tot;
int cnt[100010];
int ans;
signed main(){
	for(int i=1;i<=6;++i) a[i]=read();
	n=read();
	for(int i=1;i<=n;++i) b[i]=read();
	sort(b+1,b+n+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=6;++j) g[++tot]=node{b[i]-a[j],i};
	sort(a+1,a+7);
	sort(g+1,g+tot+1);
	int num=0;
	ans=0x3f3f3f3f;
	for(int l=1,r=0;l<=tot&&r<=tot;++l){
		if(l>1){
			--cnt[g[l-1].tp];
			if(cnt[g[l-1].tp]==0) --num;
		}
		while(num<n&&r<=tot){
			++r;
			if(cnt[g[r].tp]==0) ++num;
			++cnt[g[r].tp];
		}
		if(r<=tot) ans=min(ans,g[r].x-g[l].x);
	}
	printf("%lld\n",ans);
	return 0;
}