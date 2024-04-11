#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pa;
priority_queue<pa,vector<pa>,greater<pa> > heap;
multiset<int> gt;
typedef multiset<int>::iterator iter;
const int N=2e3+2;
iter it;
int ys[N];
int n,m,c,fh,i,t,dt,gs,j,ans=1e9;
struct pp
{
	int x,y;
	bool operator<(pp &a) {return x<a.x;}
};
pp a[N],b[N],d[N];
inline void read(int &x)
{
	c=getchar();fh=1;
	while ((c<48)||(c>57))
	{
		if (c=='-') {c=getchar();fh=-1;break;}
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
	read(n);read(m);
	for (i=1;i<=n;i++) {read(a[i].x);read(a[i].y);}
	for (i=1;i<=m;i++) {read(b[i].x);read(b[i].y);}
	sort(a+1,a+n+1);sort(b+1,b+m+1);d[gs=1]=b[1];
	for (i=2;i<=m;i++) {while ((gs)&&(b[i].y>=d[gs].y)) --gs;if ((!gs)||(b[i].x>d[gs].x))d[++gs]=b[i];}m=gs;
	for (i=1;i<=m;i++) b[i]=d[i];
	for (i=1;i<=n;i++) {for (j=1;j<=m;j++) if (a[i].x<=b[j].x) {ys[i]=j;break;}}
	//for (i=1;i<=n;i++) printf("%d ",ys[i]);puts("");
	for (i=1;i<=n;i++) if ((ys[i])&&(b[ys[i]].y>=a[i].y)) {heap.push(make_pair(b[ys[i]].x-a[i].x,i));gt.insert(b[ys[i]].y-a[i].y);}
	c=-1;for (i=1;i<=n;i++) if ((ys[i])&&(b[ys[i]].y>=a[i].y)) c=max(c,b[ys[i]].y-a[i].y);
	ans=min(ans,c+1);
	while (!heap.empty())
	{
		int d;
		c=heap.top().first;d=heap.top().second;
		while ((!heap.empty())&&(heap.top().first==c))
		{
			i=heap.top().second;heap.pop();
			gt.erase(gt.find(b[ys[i]].y-a[i].y));
			if ((++ys[i]<=m)&&(b[ys[i]].y>=a[i].y)) {heap.push(make_pair(b[ys[i]].x-a[i].x,i));gt.insert(b[ys[i]].y-a[i].y);}
		}
		dt=c;
		//printf("%d\n",dt);
		if (gt.empty()) ans=min(ans,dt+1); else {it=gt.end();--it;ans=min(ans,dt+*it+2);}//printf("%d %d\n",dt,*it);}
	}
	if (ans==int(1e9)) ans=0;
	printf("%d",ans);
}