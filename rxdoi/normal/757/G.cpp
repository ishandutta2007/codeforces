#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
#define Rep(x) for (int i=las[x],y;~i;i=E[i].nxt) if (!vis[y=E[i].y])
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

const int len=200000;
inline char nc(){
	static char buf[len],*b=buf+len;
	if (b==buf+len) fread(buf,1,len,stdin),b=buf;
	return *b++;
}
int IN(){
	int c,f,x;
	while (!isdigit(c=nc())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=nc())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}
void Output(ll x){
	if (x>=10) Output(x/10);
	putchar(x%10+'0');
}

const int N=200000+19;
const int oo=(1<<30)-1;

struct Edge{
	int y,z,nxt;
} E[N*2];

vector<int> Vx[N*2];
vector<ll> Vsum[N*2];

struct Info{
	int x;
	ll dis;
};vector<Info> I[N];

Vi pos[N];
int las[N],A[N],sz[N],vis[N],id[N],T[N*2];
int n,Qc,cnt,x,y,z,mn,cen,fcen,tot,l,r;
ll res;

void Link(int x,int y,int z){
	E[cnt]=(Edge){y,z,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,z,las[y]};las[y]=cnt++;
}
void findcen(int x,int fa,int n){
	int mx=0;
	sz[x]=1;
	Rep(x) if (y!=fa){
		findcen(y,x,n);
		sz[x]+=sz[y];
		mx=max(mx,sz[y]);
	}
	mx=max(mx,n-sz[x]);
	if (mx<mn) mn=mx,cen=x,fcen=fa;
}
void dfs(int x,int fa,ll dis){
	I[x].pb((Info){cen,dis});
	I[x].pb((Info){tot,dis});
	Rep(x) if (y!=fa) dfs(y,x,dis+E[i].z);
}
void Work(int x,int n){
	mn=oo;
	findcen(x,-1,n);
	vis[x=cen]=1;
	if (~fcen) sz[fcen]=n-sz[x];
	I[x].pb((Info){x,0});
	Rep(x){
		tot++;
		dfs(y,x,E[i].z);
	}
	Rep(x) Work(y,sz[y]);
}
ll calc(int x,ll dis,int y){
	int pos=upper_bound(Vx[x].begin(),Vx[x].end(),y)-Vx[x].begin()-1;
	if (pos==-1) return 0;
	return Vsum[x][pos]+1ll*(pos+1)*dis;
}
int find(int i,int x){
	int pos=lower_bound(Vx[i].begin(),Vx[i].end(),x)-Vx[i].begin();
	if (pos>=Vx[i].size()||Vx[i][pos]!=x) return -1;
	return pos;
}

int main(){
	//freopen("G.in","r",stdin);
	memset(las,-1,sizeof(las));
	tot=n=IN();Qc=IN();
	For(i,1,n+1){
		A[i]=IN();
		id[A[i]]=i;
	}
	For(i,1,n){
		x=IN(),y=IN(),z=IN();
		Link(x,y,z);
	}
	Work(1,n);
	For(i,1,n+1){
		for (Info tmp:I[A[i]]){
			Vx[tmp.x].pb(i);
			Vsum[tmp.x].pb(tmp.dis);
		}
	}
	For(i,1,tot+1){
		For(j,0,Vx[i].size()) pos[A[Vx[i][j]]].pb(i);
		For(j,1,Vx[i].size()) Vsum[i][j]+=Vsum[i][j-1];
	}
	while (Qc--)
		if (IN()==1){
			l=IN()^res;r=IN()^res;x=IN()^res;
			res=0;
			for (Info tmp:I[x]){
				ll val=calc(tmp.x,tmp.dis,r)-calc(tmp.x,tmp.dis,l-1);
				if (tmp.x<=n) res+=val;else res-=val;
			}
			Output(res);
			puts("");
			res%=1<<30;
		} else{
			int tmp,a,b;
			x=IN()^res;
			a=A[x],b=A[x+1];
			++*T;
			for (int i:pos[a]){
				if (T[i]==*T) continue;
				T[i]=*T;
				tmp=find(i,x);
				if (tmp+1<Vx[i].size()&&Vx[i][tmp+1]==x+1){
					Vsum[i][tmp]=(tmp-1<0?0:Vsum[i][tmp-1])+Vsum[i][tmp+1]-Vsum[i][tmp];
				} else{
					Vx[i][tmp]++;
				}
			}
			for (int i:pos[b]){
				if (T[i]==*T) continue;
				T[i]=*T;
				tmp=find(i,x+1);
				if (tmp-1>=0&&Vx[i][tmp-1]==x){
					Vsum[i][tmp-1]=(tmp-2<0?0:Vsum[i][tmp-2])+Vsum[i][tmp]-Vsum[i][tmp-1];
				} else{
					Vx[i][tmp]--;
				}
			}
			swap(A[x],A[x+1]);
		}
}