#include<bits/stdc++.h>
using namespace std;
#define MN 300005
#define LL long long
#define mp make_pair
#define fir first
#define int long long
#define sec second
#define pii pair<int,int>
inline void chkmax(int &a,int b){if(a<b)a=b;}
inline void chkmin(int &a,int b){if(a>b)a=b;}
inline int read(){
	   int a=0,fh=1;char c=getchar();
	   while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	   while('0'<=c&&c<='9'){
		   a=a*10+c-48;
		   c=getchar();
	   }
	   return a*fh;
}
//[edge to son][col]
#define Mod 998244353
vector<int>edge[MN];
LL f[MN][2][2],tmp[2][2];
int n,fa[MN];
void dfs(int x){
	f[x][0][0]=1;f[x][0][1]=1;
	for(int i=0;i<edge[x].size();++i){
		if(fa[x]==edge[x][i])continue;
		fa[edge[x][i]]=x;
		dfs(edge[x][i]);
		int v=edge[x][i];
		for(int j=0;j<2;++j)for(int k=0;k<2;++k)tmp[j][k]=f[x][j][k];
		
		f[x][0][0]*=(f[v][0][0]+f[v][1][0]+f[v][1][1])%Mod;
		f[x][0][1]*=(f[v][0][0]+f[v][1][0]+f[v][1][1])%Mod;
		f[x][1][0]=(f[x][1][0]*((f[v][0][0]*2+f[v][0][1]+f[v][1][1]*2+f[v][1][0]*2)%Mod)%Mod+tmp[0][0]*((f[v][0][0]+f[v][0][1]+f[v][1][1]+f[v][1][0])%Mod))%Mod;
		f[x][1][1]=(f[x][1][1]*((f[v][0][0]+f[v][1][0]*2+f[v][0][1]+f[v][1][1])%Mod)%Mod+tmp[0][1]*(f[v][0][0]+f[v][1][0]))%Mod;
		
	//	if(x==3)cerr<<"???  "<<f[x][1][0]<<" "<<f[x][0][1]<<" "<<f[x][0][0]<<endl;
		for(int j=0;j<2;++j)for(int k=0;k<2;++k)f[x][j][k]%=Mod;
	}
	
	//	for(int j=0;j<2;++j)for(int k=0;k<2;++k)
	//	cerr<<x<<" "<<j<<" "<<k<<": "<<f[x][j][k]<<endl;
}
char ch[15];
signed main(){
	scanf("%s",ch+1);
	puts((ch[7]-'0')%2==1?"1":"0");
	return 0;
}