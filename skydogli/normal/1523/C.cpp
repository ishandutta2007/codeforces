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
#define MN 1005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
int T,n,m;
int a[MN];
char ch[MN];
bool vis[MN][MN];
int to[MN][MN];
int cnt=1;
int st[MN<<1];
int top;
bool dfs(int x,int v){
	for(int i=1;i<=n;++i)
		if(to[x][i]&&!to[x][i+1]){
//			cerr<<"fkfk: "<<x<<" "<<i<<endl;
			st[++top]=i;
			if(dfs(to[x][i],v))return 1;
			top--;
		}
		else if(!to[x][i])break;
//	cerr<<"? "<<x<<" "<<v<<" "<<endl;
	if((v==1||to[x][v-1])&&!to[x][v]){
		to[x][v]=++cnt;
		st[++top]=v;
		return 1;	
	}
	return 0;
}
signed main(){
	T=read();
	while(T--){
		n=read();
		cnt=1;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)vis[i][j]=0;
		for(int i=1;i<=n;++i){
			int a=read();
			dfs(1,a);
			assert(top);
			for(int i=1;i<=top;++i){
				printf("%lld%c",st[i],i==top?'\n':'.');
			}
			top=0;
		}
		for(int i=1;i<=cnt;++i)
			for(int j=1;j<=n;++j)
				to[i][j]=0;
	}
	return 0;
}