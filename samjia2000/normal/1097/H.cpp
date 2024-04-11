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

const int N = 3e4+5;
const int M = 65;

int d,m;
int g[25];
int b[N],n;
bool can[N][16][M];
LL mi[N];
LL L,R;
LL f[M][M][M];
int digi[M],a[M];
int sum[N*20];
int sec[N],k,start[N],val[N];
bool yes1[M],yes2[M];

LL solve(LL r){
	if (r<0)return 0; 
	for(LL i=0,x=r;i<=60;x/=d,i++)digi[i]=x%d;
	int L=0;
	for(;mi[L]<=n;L++);
	fo(i,0,60)fo(p,0,m-1)fo(u,0,m-1)f[i][p][u]=0;
	int pp=0,uu=g[1];
	fd(i,60,1){
		fo(x,0,digi[i]-1){
			int p=(pp+g[x])%m;
			int u;
			if (x==d-1)u=(uu+m-g[x])%m;else u=(g[x+1]+m-g[x])%m;
			f[i][p][u]++;
		}
		pp=(pp+g[digi[i]])%m;
		if (digi[i]==d-1)uu=(uu+m-g[d-1])%m;
		else uu=(g[digi[i]+1]+m-g[digi[i]])%m;
		fo(p,0,m-1)
			fo(u,0,m-1)
			if (f[i][p][u]){
				fo(x,0,d-1){
					int p_=(p+g[x])%m;
					int u_;
					if (x==d-1)u_=(u+m-g[x])%m;
					else u_=(g[x+1]+m-g[x])%m;
					f[i-1][p_][u_]+=f[i][p][u];
				}
			}
	}
	LL ret=0;
	int p1=0,u1=g[1];
	fd(i,60,L){
		p1=(p1+g[digi[i]])%m;
		if (digi[i]==d-1)u1=(u1+m-g[d-1])%m;
		else u1=(g[digi[i]+1]+m-g[digi[i]])%m;
	}
	fo(i,0,mi[L]-1){
		sum[i]=0;
		for(int x=i;x;x/=d)sum[i]+=g[x%d];
		sum[i]%=m;
	}
	int cnt=0;
	fo(st,0,mi[L]-1){
		k=0;
		int mid=-1;
		for(int x=1,now=st;x<=n;){
			int w1=0,w2=0;
			for(;x+mi[w1+1]-1<=n;w1++);
			for(;w2<L&&now%mi[w2+1]==0;w2++);
			int w=min(w1,w2);
			sec[++k]=w;
			start[k]=x;
			val[k]=now;
			x+=mi[w];
			now+=mi[w];
			if (now>=mi[L])mid=k+1,now-=mi[L];
		}
		if (mid==-1)mid=k+1;
		fo(i,0,m-1)yes1[i]=yes2[i]=1;
		fo(i,1,mid-1)
			fo(p,0,m-1)yes1[p]&=can[start[i]][sec[i]][(p+sum[val[i]])%m];
		fo(i,mid,k)
			fo(p,0,m-1)yes2[p]&=can[start[i]][sec[i]][(p+sum[val[i]])%m];
		fo(p,0,m-1)
		if (yes1[p])
			fo(u,0,m-1)
			if (yes2[(p+u)%m]){
				ret=ret+f[L][p][u];
				cnt++;
			}
		if (yes1[p1]&&yes2[(p1+u1)%m]&&r%mi[L]>=st)ret++;
	}
	return ret;
}

int main(){
	d=get();m=get();
	fo(i,0,d-1)g[i]=get();
	n=get();
	fo(i,1,n)b[i]=get();
	mi[0]=1;
	fo(i,1,16)mi[i]=mi[i-1]*d;
	fd(i,n,1){
		fo(p,0,b[i])can[i][0][p]=1;
		for(int j=1;i+mi[j]-1<=n;j++)
			fo(p,0,m-1){
				can[i][j][p]=1;
				fo(x,0,d-1)can[i][j][p]&=can[i+x*mi[j-1]][j-1][(p+g[x])%m];
			}
	}
	cin>>L>>R;
	R=R-n+1;
	L--,R--;
	LL vr=solve(R);
	LL vl=solve(L-1);
	cout<<vr-vl<<endl;
	return 0;
}