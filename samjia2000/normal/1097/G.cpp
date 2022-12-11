#include<bits/stdc++.h>

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

const int N = 1e5+5;
const int K = 205;
const int mo = 1e9+7;

int n,k;
struct edge{
	int x,nxt;
}e[N*2];
int h[N],tot;

void inse(int x,int y){e[++tot].x=y;e[tot].nxt=h[x];h[x]=tot;}

int siz[N];
LL mi[N];

LL js[K],inv[K];

LL calc(int n,int m){return js[n]*inv[m]%mo*inv[n-m]%mo;}

LL ans;

LL f[N][K];
LL g[K][K];
int tp[N];

void dfs(int x){
	siz[x]=1;
	LL pre=1;
	LL ad=0;
	for(int p=h[x];p;p=e[p].nxt)
		if (!siz[e[p].x]){
			int y=e[p].x;
			dfs(y);
			ans=(ans+(mi[siz[y]]-1)*(mi[n-siz[y]]-1))%mo;
			tp[y]=min(siz[y],k);
			fo(i,1,tp[y])ans=(ans+(mi[n-siz[y]]-1)*f[y][i]%mo*g[i+1][k])%mo;
			fd(i,tp[y],1)f[y][i+1]=(f[y][i+1]+f[y][i])%mo;
			f[y][1]=(f[y][1]+(mi[siz[y]]-1))%mo;
			ad=ad*mi[siz[y]]%mo;
			fd(i,tp[x],1){
				fo(j,1,tp[y])
				if (i+j<=k){
					LL tmp=f[x][i]*f[y][j]%mo;
					ad=(ad+tmp*g[i+j][k]%mo)%mo;
					f[x][i+j]=(f[x][i+j]+tmp)%mo;
				}
				f[x][i]=f[x][i]*mi[siz[y]]%mo;
			}
			//fo(i,1,tp[x])f[x][i]=f[x][i]*mi[siz[y]]%mo;
			fo(i,1,tp[y])f[x][i]=(f[x][i]+f[y][i]*pre)%mo;
			siz[x]+=siz[y];
			tp[x]=min(siz[x],k);
			pre=pre*mi[siz[y]]%mo;
		}
	ad=ad*mi[n-siz[x]+1]%mo;
	ans=(ans+ad)%mo;
	fo(i,1,tp[x])f[x][i]=f[x][i]*2%mo;
}

int main(){
	n=get();k=get();
	fo(i,2,n){
		int x=get(),y=get();
		inse(x,y),inse(y,x);
	}
	js[0]=js[1]=1;
	fo(i,2,k)js[i]=js[i-1]*i%mo;
	inv[0]=inv[1]=1;
	fo(i,2,k)inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	fo(i,2,k)inv[i]=inv[i]*inv[i-1]%mo;
	g[0][0]=1;
	fo(i,0,k-1)
		fo(j,0,k)
			fo(x,1,k-j)
			g[i+1][j+x]=(g[i+1][j+x]+g[i][j]*calc(j+x,x))%mo;
	mi[0]=1;
	fo(i,1,n)mi[i]=mi[i-1]*2%mo;
	dfs(1);
	cout<<ans<<endl;
	return 0;
}