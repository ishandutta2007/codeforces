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
#define vc vector
int a[MN],id[MN],n;
int ans[MN][MN];
bool cmp(int x,int y){return a[x]>a[y];}
signed main(){
	n=read();
	for(int i=1;i<=n;++i)a[i]=read(),id[i]=i;
	sort(id+1,id+1+n,cmp);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=a[id[i]];++j)
			ans[(i+j-1-1)%(n+1)+1][id[i]]=1;
	printf("%lld\n",n+1);
	for(int i=1;i<=n+1;++i){
		for(int j=1;j<=n;++j)
			putchar(ans[i][j]+'0');
		puts("");
	}
	return 0;
}