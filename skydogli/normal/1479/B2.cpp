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
#define MN 200005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
int T,n,m;
int a[MN],b[MN];
int nxt[MN],vis[MN];
signed main(){
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i){
		if(a[i]!=a[i-1])b[++m]=a[i];
	}
	for(int i=1;i<=m;++i)
		vis[b[i]]=m+1;
	for(int i=m;i;--i){
		nxt[i]=vis[b[i]];	
		vis[b[i]]=i;
	}
	int ans=0,x=0,y=0;
	nxt[0]=m+1;
	for(int i=1;i<=m;++i){
		if(b[x]!=b[i]&&b[y]!=b[i]){
			ans++;
			if(nxt[x]>nxt[y]){
				x=i;
			}
			else y=i;
		}
		else if(b[x]==b[i])x=i;
		else y=i;
	}
	printf("%lld\n",ans);
	return 0;
}