#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 4005;
const int L = 38;
const int mo = 998244353;

int k;
struct edge{
	int x,nxt;
};
LL js[N],inv[N],val[N];
LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}
LL dec(LL x,LL y){return x<y?x-y+mo:x-y;}
LL quickmi(LL x,LL tim){
	LL ret=1;
	for(;tim;tim/=2,x=x*x%mo)
	if (tim&1)ret=ret*x%mo;
	return ret;
}

struct TREE{
	int n;
	int h[N],tot;
	edge e[N*2];
	
	void inse(int x,int y){e[++tot].x=y;e[tot].nxt=h[x];h[x]=tot;}
	
	void read(){
		fo(i,1,n)h[i]=0;
		tot=0;
		fo(i,2,n){
			int x=get(),y=get();
			inse(x,y),inse(y,x);
		}
	}
	
	LL f[N][L][L];
	LL g[L][L],s[L];
	bool vis[N];
	int fa[N];
	
	void dfs(int x){
		vis[x]=1;
		for(int p=h[x];p;p=e[p].nxt)
		if (!vis[e[p].x]){
			fa[e[p].x]=x;
			dfs(e[p].x);
		}
		fo(i,0,k)fo(j,0,k)f[x][i][j]=0;
		f[x][0][0]=1;
		for(int p=h[x];p;p=e[p].nxt)
		if (fa[e[p].x]==x){
			int y=e[p].x;
			fo(i,0,k)fo(j,0,k)g[i][j]=0;
			fo(a,0,k)
				fo(b,0,a)
				if (f[x][a][b])
					fo(c,1,k-a)
						fo(d,1,c)
						g[a+c][b+d]=(g[a+c][b+d]+f[x][a][b]*f[y][c][d])%mo;
			fo(i,0,k)fo(j,0,k)f[x][i][j]=add(f[x][i][j],g[i][j]);
		}
		fo(i,0,k)fo(j,0,k)g[i][j]=0;
		fo(a,0,k)
			fo(b,0,a)
				fo(u,0,k-a)
				if (b+u)
				g[a+u][u]=(g[a+u][u]+f[x][a][b]*val[u]%mo*js[b+u-1])%mo;
		g[0][0]=add(g[0][0],1);
		fo(a,0,k)fo(b,0,k)f[x][a][b]=g[a][b];
		fo(a,1,k)s[a]=(s[a]+f[x][a][0]*a*2)%mo;
	}
	
	void solve(){
		fo(i,1,n)vis[i]=0,fa[i]=0;
		fo(i,0,k)s[i]=0;
		dfs(1);
		s[0]=n;
	}
}A,B;

void prepare(){
	js[0]=js[1]=inv[0]=inv[1]=1;
	fo(i,2,4e3)js[i]=js[i-1]*i%mo;
	fo(i,2,4e3)inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	fo(i,2,4e3)inv[i]=inv[i]*inv[i-1]%mo;
	val[0]=1;
	fo(i,1,4e3)val[i]=inv[i]*inv[i-1]%mo;
}

void getans(){
	LL ans=0;
	fo(i,0,k)ans=(ans+A.s[i]*B.s[k-i]%mo*inv[2*i]%mo*inv[2*(k-i)]%mo)%mo;
	ans=ans*js[k*2]%mo;
	cout<<ans<<endl;
}

int main(){
	prepare();
	A.n=get();B.n=get();k=get();
	if (k&1)return printf("0\n"),0;
	A.read();
	B.read();
	k/=2;
	A.solve();
	B.solve();
	getans();
	return 0;
}