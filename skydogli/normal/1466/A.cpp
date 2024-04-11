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
int a[MN],x[MN],vis[MN];
char ch[MN];
signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i)x[i]=read();
		for(int i=1;i<=100;++i)vis[i]=0;
		int ans=0;
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j)
				if(!vis[x[j]-x[i]])vis[x[j]-x[i]]=1,ans++;
		printf("%lld\n",ans);
	}
	return 0;
}