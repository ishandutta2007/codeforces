#include<iostream>
#include<cstdio>
#include<cstring>
#include<bitset>
#include<algorithm>
#include<map>
#include<set>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

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

const int N = 2005;

int n,m1,m2;
struct edge{
	int x,nxt;
};
struct two_satisfiability{
	edge e[N*N];
	int h[N],tot;
	
	void inse(int x,int y){e[++tot].x=y;e[tot].nxt=h[x];h[x]=tot;}
	
	void read(int m){
		fo(i,1,n*2+1)h[i]=0;
		tot=k=u=0;
		fo(i,1,m){
			int x=get(),y=get();
			if (x>0)x=x*2;else x=-2*x+1;
			if (y>0)y=y*2;else y=-2*y+1;
			inse(x,y^1);
			inse(y,x^1);
		}
	}
	
	int k,dfn[N],f[N];
	int be[N],u;
	int sta[N],top;
	bool pd[N];
	
	void tarjan(int x){
		dfn[x]=f[x]=++k;
		pd[sta[++top]=x]=1;
		for(int p=h[x];p;p=e[p].nxt)
		if (!dfn[e[p].x]){
			tarjan(e[p].x);
			f[x]=min(f[x],f[e[p].x]);
		}
		else if(pd[e[p].x])f[x]=min(f[x],dfn[e[p].x]);
		if (f[x]==dfn[x]){
			u++;
			while(sta[top+1]!=x){
				pd[sta[top]]=0;
				be[sta[top]]=u;
				top--;
			}
		}
	}
	
	bitset<N> can[N];
	int vis[N],tim;
	bool sol;
	bool both[N][N];
	int nd[10];
	bool tr[10][10];
	
	bool circle(int x){
		if (vis[x]==tim)return 1;
		vis[x]=tim;
		fo(i,1,4)
		if(x!=i&&tr[x][i])
		if (circle(i))return 1;
		vis[x]=tim-1;
		return 0;
	}
	
	void build(const bool sig=0){
		k=u=top=tim=0;
		fo(i,1,n*2+1)pd[i]=0,vis[i]=dfn[i]=f[i]=be[i]=0;
		fo(i,2,n*2+1)if (!dfn[i])tarjan(i);
		fo(i,1,u)can[i].reset();
		fo(i,1,u)can[i][i]=1;
		fo(i,1,u){
			fo(x,2,n*2+1)
			if (be[x]==i)
				for(int p=h[x];p;p=e[p].nxt)
				if (be[e[p].x]!=be[x])can[i]=can[i]|can[be[e[p].x]];
		}
		sol=1;
		fo(i,1,n)if(be[i*2]==be[i*2+1])sol=0;
		if (sig)return;
		fo(i,2,n*2+1)
		if (!can[be[i]][be[i^1]])
			fo(j,2,n*2+1)
			if (!can[be[j]][be[j^1]])
			if(i!=j){
				fo(x,1,4)fo(y,1,4)tr[x][y]=0;
				nd[1]=i,nd[2]=i^1;
				nd[3]=j,nd[4]=j^1;
				fo(x,1,4)fo(y,1,4)if (x!=y&&can[be[nd[x]]][be[nd[y]]])tr[x][y]=1;
				tr[2][1]=tr[4][3]=1;
				both[i][j]=1;
				fo(x,1,4){
					tim++;
					if (circle(x))both[i][j]=0;
				}
			}
	}
	
	int col[N];
	int d[N],res;
	
	void color2(int x){
		if (col[x])return;
		col[x]=2;
		fo(i,1,u)
		if (can[i][x])color2(i);
	}
	
	void getsol(){
		fo(i,1,u)d[i]=col[i]=0;
		fo(i,1,u)fo(j,1,u)if (i!=j&&can[i][j])d[i]++;
		res=u;
		while(res){
			int x;
			fo(i,1,u)
			if (!d[i]&&!col[i]){x=i;break;}
			col[x]=1;
			res--;
			fo(i,1,u)
			if (!col[i]&&can[i][x])d[i]--;
			fo(i,2,n*2+1)
			if(be[i]==x){
				color2(be[i^1]);
			}
		}
		fo(i,1,n)
		if (col[be[i*2]]==1)printf("0 ");else printf("1 ");
		putchar('\n');
	}
}A,B;

int main(){
    int tp=1;
	n=get();m1=get();m2=get();
	A.read(m1);
	B.read(m2);
	A.build();
	B.build();
	if (!A.sol&&!B.sol)return printf("SIMILAR\n"),0;
	if (!A.sol&&B.sol){
		B.getsol();
		return 0;
	}
	if (A.sol&&!B.sol){
		A.getsol();
		return 0;
	}
	fo(i,2,n*2+1)
		fo(j,2,n*2+1)
		if(A.can[A.be[j]][A.be[i]]&&B.both[i^1][j]){
			B.inse(i,i^1);
			B.inse(j^1,j);
			B.build(1);
			B.getsol();
			return 0;
		}
	
	fo(i,2,n*2+1)
		fo(j,2,n*2+1)
		if(B.can[B.be[j]][B.be[i]]&&A.both[i^1][j]){
			A.inse(i,i^1);
			A.inse(j^1,j);
			A.build(1);
			A.getsol();
			return 0;
		}
	fo(i,2,n*2+1)
	if(!A.can[A.be[i]][A.be[i^1]]&&B.can[B.be[i]][B.be[i^1]]){
			A.inse(i^1,i);
			A.build(1);
			A.getsol();
			return 0;
		}
	fo(i,2,n*2+1)
	if(A.can[A.be[i]][A.be[i^1]]&&!B.can[B.be[i]][B.be[i^1]]){
			B.inse(i^1,i);
			B.build(1);
			B.getsol();
			return 0;
		}
	printf("SIMILAR\n");
	return 0;
}