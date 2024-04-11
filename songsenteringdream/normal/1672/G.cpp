#include<cstdio>
using namespace std;
const int o=2010,MOD=998244353;
int r,c,h[o*2],cnt,pw[o*o],w[o*2],n,m,x;char b[o][o];bool vis[o*2];
struct Edge{int v,p;}e[o*o*2];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
inline int calc1(int val){
	int res=1;
	for(int i=1,t;i<=r;++i){
		t=cnt=0;
		for(int j=1;j<=c;++j) if(b[i][j]=='?') ++cnt;else if(b[i][j]=='1') t^=1;
		if(!cnt) res*=(t==val);
		else for(;--cnt;) res=res*2%MOD;
	}
	return res;
}
inline int calc2(int val){
	int res=1;
	for(int i=1,t;i<=c;++i){
		t=cnt=0;
		for(int j=1;j<=r;++j) if(b[j][i]=='?') ++cnt;else if(b[j][i]=='1') t^=1;
		if(!cnt) res*=(t==val);
		else for(;--cnt;) res=res*2%MOD;
	}
	return res;
}
void dfs(int nw,int fa){
	vis[nw]=1;++n;x^=w[nw];
	for(int i=h[nw];i;i=e[i].p) if(e[i].v^fa)
		if(!vis[e[i].v]) dfs(e[i].v,nw);
		else ++m;
}
inline int calc3(int val){
	int res=1;
	for(int i=1;i<=r+c;++i) vis[i]=0;
	for(int i=1;i<=r+c;++i) if(!vis[i]){
		n=m=x=0;dfs(i,0);
		if(x==val*(n&1)) res=res*1ll*pw[m/2]%MOD;else res=0;
	}
	return res;
}
int main(){
	scanf("%d%d",&r,&c);
	for(int i=1;i<=r;++i) scanf("%s",b[i]+1);
	for(int i=pw[0]=1;i<=r*c;++i) pw[i]=pw[i-1]*2%MOD;
	if(r%2==0&&c%2==0){
		for(int i=1;i<=r;++i) for(int j=1;j<=c;++j) if(b[i][j]=='?') ++cnt;
		printf("%d",pw[cnt]);
		return 0;
	}
	if(r%2==0){printf("%d",(calc1(0)+calc1(1))%MOD);return 0;}
	if(c%2==0){printf("%d",(calc2(0)+calc2(1))%MOD);return 0;}
	for(int i=1;i<=r;++i) for(int j=1;j<=c;++j)
		if(b[i][j]=='?') ad(i,j+r),ad(j+r,i);else if(b[i][j]=='1') w[i]^=1,w[j+r]^=1;
	printf("%d",(calc3(0)+calc3(1))%MOD);
	return 0;
}