#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int T,n,m;
int ans[1010][1010];
int mat[1010][1010];
char str[100010];
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j) mat[i][j]=read();
		}
		scanf("%s",str+1);
		vector<int>a(n*n+1),b(n*n+2),c(n*n+1);
		a[0]=b[0]=c[0]=0;
		auto getid=[&](int x,int y){
			return n*(x-1)+y;
		};
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				a[getid(i,j)]=i,b[getid(i,j)]=j,c[getid(i,j)]=mat[i][j];
			}
		} 
		for(int i=1;i<=m;++i){
			switch(str[i]){
				case 'R': ++b[0]; break;
				case 'L': --b[0]; break;
				case 'D': ++a[0]; break;
				case 'U': --a[0]; break;
				case 'I': swap(b,c); break;
				case 'C': swap(a,c); break;
			}
		}
		for(int i=1;i<=n*n;++i){
			int x=a[i]+a[0],y=b[i]+b[0],z=c[i]+c[0];
			x=(x%n+n)%n,y=(y%n+n)%n,z=(z%n+n)%n;
			if(x==0) x=n;if(y==0) y=n;if(z==0) z=n;
			ans[x][y]=z;
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j) printf("%d ",ans[i][j]);
			printf("\n");
		}
		printf("\n");
	}
}