#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define MN 200005
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
int T,n,m;
char ch[MN];
int a[MN];
int p,k,suf[MN];
signed main(){
//	for(int i=1;i<=n;++i)a[i]=read();
	T=read();
	while(T--){
		n=read();p=read();k=read();
		scanf("%s",ch+1);
		int x=read(),y=read();
		suf[n+1]=0;
		int ans=1e18;
		for(int i=n;i>=p;--i){
			suf[i]=suf[i+k]+(ch[i]=='0');
			ans=min(ans,(i-p)*y+x*suf[i]);
		}
		for(int i=1;i<=n;++i)suf[i]=0;
		printf("%lld\n",ans);
	}
	
	return 0;
}