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
int n,k;
int a[500010];
int b[500010];
int ans;
int g[500010];
int len;
void solve(int l,int r){
	len=0;
	g[++len]=a[l]-l;
	for(int i=l+1;i<r;++i){
		if(a[i]-i<a[l]-l||a[i]-i>a[r]-r) continue ;
		if(a[i]-i>=g[len]){
			g[++len]=a[i]-i;continue ;
		}
		int j=upper_bound(g+1,g+len+1,a[i]-i)-g;
		g[j]=a[i]-i;
	}
	ans-=(len-1);
}
signed main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=k;++i) b[i]=read();
	a[0]=-0x3f3f3f3f;
	b[0]=0,b[k+1]=n+1;a[n+1]=0x3f3f3f3f;
	ans=n-k;
	for(int i=0;i<=k;++i) if(a[b[i+1]]-a[b[i]]<b[i+1]-b[i]){
		printf("-1\n");exit(0);
	} 
	for(int i=0;i<=k;++i){
		solve(b[i],b[i+1]);
	}
	print(ans);
}