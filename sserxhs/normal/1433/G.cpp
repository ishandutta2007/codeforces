#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
priority_queue<pa,vector<pa>,greater<pa> > heap;
pa ins;
const int N=1e3+2,M=1e3+2;
struct Q
{
	int u,v;
	Q(int a=0,int b=0):u(a),v(b){}
};
vector<Q> lj[N];
ll ans=1e18,na;
int ls[M][3],jl[N],tjl[N][N],a[N],b[N];
int n,m,i,j,k,q,c,fh,x,y,z;
bool ed[N];
inline void read(int &x)
{
	c=getchar();fh=1;
	while ((c<48)||(c>57))
	{
		if (c=='-') {fh=-1,c=getchar();break;}
		c=getchar();
	}
	x=c^48;c=getchar();
	while ((c>=48)&&(c<=57))
	{
		x=x*10+(c^48);
		c=getchar();
	}
	x*=fh;
}
int main()
{
	read(n);read(m);read(q);
	for (i=1;i<=m;i++) {read(ls[i][1]);read(ls[i][2]);read(ls[i][0]);lj[ls[i][1]].push_back(Q(ls[i][2],ls[i][0]));lj[ls[i][2]].push_back(Q(ls[i][1],ls[i][0]));}
	for (k=1;k<=n;k++)
	{
		memset(jl,0x3f,sizeof(jl));jl[k]=0;
		memset(ed,0,sizeof(ed));
		while (!heap.empty()) heap.pop();
		heap.push(make_pair(0,k));
		while (!heap.empty())
		{
			ed[x=heap.top().second]=1;heap.pop();//printf("IN %d\n",x);
			for (i=0;i<lj[x].size();i++) if (jl[lj[x][i].u]>jl[x]+lj[x][i].v) heap.push(make_pair(jl[lj[x][i].u]=jl[x]+lj[x][i].v,lj[x][i].u));
			while ((!heap.empty())&&(ed[heap.top().second])) heap.pop(); 
		}
		for (i=1;i<=n;i++) tjl[k][i]=jl[i];
		//for (i=1;i<=n;i++) printf("%d %d: %d\n",k,i,tjl[k][i]);
	}
	for (i=1;i<=q;i++) {read(a[i]);read(b[i]);}
	for (i=1;i<=m;i++)
	{
		na=0;
		for (j=1;j<=q;j++) na+=min(tjl[a[j]][b[j]],min(tjl[a[j]][ls[i][1]]+tjl[b[j]][ls[i][2]],tjl[b[j]][ls[i][1]]+tjl[a[j]][ls[i][2]]));
		ans=min(ans,na);
	}
	printf("%lld",ans);
}