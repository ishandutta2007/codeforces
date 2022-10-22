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
#define MN 505
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
int T,n,m,k,q;
int a[MN][MN],p[MN];
void dfs(int x,int y,int &tot,int col){
	a[x][y]=col;tot--;
	if(!tot)return;
	if(y>1&&!a[x][y-1])dfs(x,y-1,tot,col);
	if(!tot)return;
	dfs(x+1,y,tot,col);
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i){
		p[i]=read();
		dfs(i,i,p[i],p[i]);
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)
			printf("%lld%c",a[i][j],j==i?'\n':' ');
	return 0;
}