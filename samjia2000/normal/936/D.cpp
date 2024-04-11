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

const int N = 1000005;
const int INF = 1.05e9;

int n,m[2],t;
int a[2][N];
set<int>s[2];
int nxt[2][N];
int f[2][N],lst[2][N];
map<int,int>id[2];
int key[N*2],k;
struct addition{
	int l,r,co;
	addition(const int l_=0,const int r_=0,const int co_=0){l=l_;r=r_;co=co_;}
	friend bool operator <(addition a,addition b){return a.l!=b.l?a.l<b.l:(a.r!=b.r?a.r<b.r:a.co<b.co);}
};
set<addition>ad[2];
int turn[N*2],M;
struct bomb{
	int u,x;
	bomb(const int u_=0,const int x_=0){u=u_;x=x_;}
	friend bool operator < (bomb a,bomb b){return a.x<b.x;}
}bob[N*2];
int kb;

int getw(int u,int x){
	int l=1,r=m[u],ret=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (a[u][mid]>=x){ret=mid;r=mid-1;}
		else l=mid+1;
	}
	return ret;
}

void walk(int u,int x,int tu,int tx,int lim){
	int rig,h=getw(u,max(x,lim));
	if (!h)rig=n;
	else rig=a[u][h]-1;
	if (rig>=tx){if (u!=tu)turn[++M]=tx;return;}
	turn[++M]=rig;
	walk(u^1,rig,tu,tx,lim);
}

int fans[N*2];

void getans(int u,int x,int tu,int tx){
	printf("Yes\n");
	M=0;
	walk(u,f[u][x],tu,tx,a[u][x]);
	for(int nu=u,nx=x;nx;){
		int co=lst[nu][nx];
		if (f[nu][nx])bob[++kb]=bomb(nu,f[nu][nx]);
		if (co==-1)nx--;
		else{
			if(co){
				walk((co&1),f[co&1][co>>1],nu,f[nu][nx],a[co&1][co>>1]);
				nu=co&1,nx=co>>1;
			}
			else{
				nx=0;
				if (nu)turn[++M]=0;
			}
		}
	}
	sort(turn+1,turn+1+M);
	turn[0]=-INF,turn[M+1]=INF;
	int M_=0;
	fo(i,1,M)if (turn[i]!=turn[i-1]&&turn[i]!=turn[i+1])fans[++M_]=turn[i];
	printf("%d\n",M_);
	fo(i,1,M_)printf("%d ",fans[i]);putchar('\n');
	sort(bob+1,bob+1+kb);
	printf("%d\n",kb);
	fo(i,1,kb)printf("%d %d\n",bob[i].x,bob[i].u+1);
}

int getw(int x){
	int l=1,r=k,ret=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (key[mid]<x)l=mid+1;
		else r=mid-1,ret=mid;
	}
	return ret;
}

int td[N*2][2];

int main(){
	n=get();m[0]=get();m[1]=get();t=get();
	fo(i,1,m[0])id[0][key[++k]=a[0][i]=get()]=i;
	fo(i,1,m[1])id[1][key[++k]=a[1][i]=get()]=i;
	m[0]++;id[0][key[++k]=a[0][m[0]]=n+1]=m[0];
	m[1]++;id[1][key[++k]=a[1][m[1]]=n+1]=m[1];
	sort(key+1,key+1+k);
	int k_=1;
	fo(i,2,k)if (key[i]>key[i-1])key[++k_]=key[i];
	k=k_;
	fo(i,1,m[0])td[getw(a[0][i])][0]=i;
	fo(i,1,m[1])td[getw(a[1][i])][1]=i;
	key[0]=-1e9;key[k+1]=2e9;
	fd(i,k,1){
		int x=key[i];
		if (td[i][0]&&td[i][1]){nxt[0][td[i][0]]=nxt[1][td[i][1]]=x-1;continue;}
		fo(u,0,1)
		if (td[i][u]){
			int p=td[i][u];
			if (key[i-1]==key[i]-1&&td[i-1][u^1])nxt[u][p]=x-1;
			else
				if (key[i+1]==key[i]+1&&td[i+1][u^1])nxt[u][p]=x;
				else{
					int h=getw(u^1,x);
					if (!h)nxt[u][p]=n;
					else
						if (p==m[u])nxt[u][p]=n;
						else{
							int w=h;
							nxt[u][p]=a[u][p+1]<a[u^1][w]?nxt[u][p+1]:nxt[u^1][w];
						}
				}
		}
	}
	fo(i,0,1)fo(j,1,m[i]+1)f[i][j]=INF;
	f[0][1]=f[1][1]=0;
	fo(i,1,k){
		int x=key[i];
		fo(u,0,1)
		if (id[u][x]){
			int p=id[u][x];
			if (p>1){
				if (f[u][p-1]+t<a[u][p-1]&&f[u][p-1]+t<f[u][p]){
					f[u][p]=f[u][p-1]+t;
					lst[u][p]=-1;
				}
			}
			if (p>2&&a[u][p-1]!=a[u][p-2]+1){
				while(ad[u].begin()!=ad[u].end()&&(*ad[u].begin()).r<=a[u][p-2])ad[u].erase(ad[u].begin());
				if (ad[u].begin()!=ad[u].end()&&(*ad[u].begin()).l<a[u][p-1]){
					int tmp=max(a[u][p-2]+1,(*ad[u].begin()).l);
					if(tmp<f[u][p]){
						f[u][p]=tmp;
						lst[u][p]=(*ad[u].begin()).co;
					}
				}
			}
		}
		if (id[0][x]&&id[1][x]){
			int i0=id[0][x],i1=id[1][x];
			if (f[0][i0]+t<=nxt[0][i0]&&i1>2&&a[1][i1-1]!=a[1][i1-2]+1&&nxt[0][i0]>a[1][i1-2]&&f[0][i0]+t<a[1][i1-1]){
				int tmp=max(a[1][i1-2]+1,f[0][i0]+t);
				if (tmp<f[1][i1]){
					f[1][i1]=tmp;
					lst[1][i1]=i0*2;
				}
			}
			if (f[1][i1]+t<=nxt[1][i1]&&i0>2&&a[0][i0-1]!=a[0][i0-2]+1&&nxt[1][i1]>a[0][i0-2]&&f[1][i1]+t<a[0][i0-1]){
				int tmp=max(a[0][i0-2]+1,f[1][i1]+t);
				if (tmp<f[0][i0]){
					f[0][i0]=tmp;
					lst[0][i0]=i1*2+1;
				}
			}
		}
		fo(u,0,1){
			int p=id[u][x];
			if(p&&f[u][p]+t<=nxt[u][p]){
				ad[0].insert(addition(f[u][p]+t,nxt[u][p],p*2+u));
				ad[1].insert(addition(f[u][p]+t,nxt[u][p],p*2+u));
			}
		}
	}
	fo(u,0,1)
	if (f[u][m[u]]<INF){
		getans(u,m[u],u,n);
		return 0;
	}
	fo(u,0,1)
		fo(i,1,m[u]-1)
		if (f[u][i]<INF&&nxt[u][i]==n){
			getans(u,i,a[0][m[0]-1]==n?1:0,n);
			return 0;
		}
	printf("No\n");
	return 0;
}