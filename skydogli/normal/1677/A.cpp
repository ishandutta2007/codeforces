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
#define MN 5005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
int T,n,m;
int a[MN],w[MN],f[MN][MN];
char ch[MN];
signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)
				f[i][j]=f[i-1][j]+(a[i]<=j);
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			int r=0;
			for(int j=i+1;j<=n;++j){	
				ans+=f[i-1][a[j]]*(a[i]-f[j][a[i]]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}