#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 500005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define Mod 1000000007
int T,n,m;
pii a[MN];
int F[MN],anc[MN][21];
int vis[MN],ok[MN];
char ch[MN];
int Find(int a){
	if(F[a]==a)return a;
	return F[a]=Find(F[a]);
}
signed main(){
	n=read();m=read();
	for(int i=1;i<=m+1;++i)F[i]=i;
	for(int i=1;i<=n;++i){
		int cnt=read();
		if(cnt==2){
			int x=read(),y=read();
			if(x<y)swap(x,y);
			a[i]=mp(x,y);
		}
		else a[i].x=read();
		a[i].x=Find(a[i].x);
		a[i].y=Find(a[i].y);
		if(a[i].x<a[i].y)swap(a[i].x,a[i].y);
//		cerr<<"? "<<a[i].x<<" "<<a[i].y<<endl;
		while(a[i].x){
			if(a[i].x==a[i].y)break;
			if(!vis[a[i].x]){
				vis[a[i].x]=i;
	//			b[a[i].x]=a[i].y;
//				cerr<<"ins: "<<a[i].x<<" "<<a[i].y<<endl;
				anc[a[i].x][0]=a[i].y;
				F[a[i].x]=Find(a[i].y);
		//		for(int i=1;i<=19;++i)
		//			anc[a[i].x][i]=anc[anc[a[i].x][i-1]][i-1];
				break;
			}
			else{
				int to=Find(a[i].x);
				if(to>a[i].y){
					a[i].x=to;
					continue;
				}
				else{
					if(to==a[i].y)break;
//					int x=a[i].x;
//					for(int i=19;i>=0;--i)
//						if(anc[x][i]>=a[i].y)anc[x][i]=a[i].y;
					a[i]=mp(a[i].y,to);
				}
			}
		}
	}
	int cnt=0,ans=1;
	for(int i=1;i<=m;++i)
		if(vis[i]){
			ans=ans*2%Mod,ok[vis[i]]=1,cnt++;
//			cerr<<"OK: "<<i<<" "<<vis[i]<<endl;
		}
	printf("%lld %lld\n",ans,cnt);
	for(int i=1;i<=n;++i)if(ok[i])printf("%lld ",i);
	return 0;
}