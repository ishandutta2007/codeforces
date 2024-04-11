#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int M=400005,N=5005*3;
int n,Q;
int type,dir,x,y,len;
int c[N];
int q[8],p[M],u[8][M],v[8][M],id[8][M],ans[M];
bool query[M];

void add(int d,int x,int y,int z)
{
	int &m=q[d];
	u[d][m]=x,v[d][m]=y,id[d][m]=z;
	++m;
}
void ins(int i,int dir,int x,int y,int len)
{
	if (dir&1) y=n+1-y;
	if (dir&2) x=n+1-x;
	if (len<0){
		add(dir,x,y,i);
		add(dir+4,x,x+y,i);
	}else{
		add(dir,x-1,y-1,-1);
		add(dir,x+len,y-1,-3);
		add(dir+4,x-1,x+y+len,-3);
		add(dir+4,x+len,x+y+len,-1);
	}
}
void add(int x,int val)
{
	for (;x<=N;x+=x&-x) c[x]+=val;
}
int get(int x)
{
	int val=0;
	for (;x>0;x-=x&-x) val+=c[x];
	return val;
}

int *U,*V,*ID;
bool cmp(const int i,const int j)
{
	return U[i]==U[j]?V[i]==V[j]?ID[i]<ID[j]:V[i]>V[j]:U[i]>U[j];
}
void solve(int l,int r,int *u,int *v,int *id)
{
	int m=(l+r)/2; if (l+1>=r) return;
	solve(l,m,u,v,id),solve(m,r,u,v,id);
	//printf("%d %d\n",l,r);
	inplace_merge(p+l,p+m,p+r,cmp);
	//for (int i=l;i<r;++i)  printf("%d ",p[i]); puts("");
	for (int i=l;i<r;++i){
		int x=p[i];
		//printf("m=%d x=%d %d\n",m,x,v[x]);
		if (x<m && id[x]<0) add(N-1-v[x],id[x]+2);
		if (x>=m && id[x]>=0){
			ans[id[x]] += get(N-1-v[x]);
			//printf("!  %d\n",get(N+1-v[x]));
		}
	}
	for (int i=l;i<r;++i){
		int x=p[i];
		if (x<m && id[x]<0) add(N-1-v[x],-(id[x]+2));
	}
}
int main()
{
	scanf("%d%d",&n,&Q);
	for (int i=0;i<Q;++i){
		scanf("%d",&type);
		if (type == 1){
			scanf("%d%d%d%d",&dir,&x,&y,&len);
			ins(i,dir-1,x,y,len);
		}else{
			scanf("%d%d",&x,&y);
			//if (x<=0 || x>n || y<=0 || y>n) for(;;);
			query[i]=1;
			for (int j=0;j<4;++j) ins(i,j,x,y,-1);
		}
	}
	for (int j=0;j<8;++j){
		//printf("j=%d\n",j);
		//for (int i=0;i<q[j];++i){
		//	printf("%d %d %d\n",u[j][i],v[j][i],id[j][i]);
		//}
		memset(c,0,sizeof(c));
		memset(p,0,sizeof(p));
		for (int i=0;i<q[j];++i) p[i]=i;
		U=u[j],V=v[j],ID=id[j];
		solve(0,q[j],U,V,ID);
	}
	for (int i=0;i<Q;++i) if (query[i])
		printf("%d\n",ans[i]);
}