#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <ctime>
#define fi first
#define se second
#define PA pair<int,int>
#define VI vector<int>
#define VP vector<PA >
#define mk(x,y) make_pair(x,y)
#define N 500010
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
struct ww {
	int l,r,a;
} tr[N*30];
int i,j,k,n,m,t;
int id[N],a[N],root[N];
VP b[N];
inline bool cc1(const int &A,const int &B) {
	return a[A]<a[B]||a[A]==a[B]&&A<B;
}
inline void update(int x) {
	int y=tr[x].l,z=tr[x].r;
	tr[x].a=min(tr[y].a,tr[z].a);
}
void gao(int p,int &q,int x,int y,int k,int A) {
	if (!q) q=++t;
	if (x==y) {
		tr[q].a=min(A,tr[p].a);
		return;
	}
	int mid=(x+y)/2;
	if (k<=mid) gao(tr[p].l,tr[q].l,x,mid,k,A),tr[q].r=tr[p].r;
	else gao(tr[p].r,tr[q].r,mid+1,y,k,A),tr[q].l=tr[p].l;
	update(q);
}
int cal(int q,int x,int y,int k) {
	if (!q) return N;
	if (y<=k) return tr[q].a;
	int mid=(x+y)/2,an=cal(tr[q].l,x,mid,k);
	if (mid<k) an=min(an,cal(tr[q].r,mid+1,y,k));
	return an;
}
int main() {
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&a[i]),id[i]=i;
	sort(id+1,id+n+1,cc1);
	for (i=1;i<=n;i=j) {
		for (j=i+1;j<=n&&a[id[i]]==a[id[j]];j++) {
			b[id[j-1]].push_back(mk(id[j],id[j]-id[j-1]));
		}
	}
	tr[0].a=N;
	for (i=n;i;i--) {
		root[i]=root[i+1];
		for (j=0;j<b[i].size();j++) {
			PA A=b[i][j];
			int last=root[i];
			root[i]=0;
			gao(last,root[i],1,n,A.fi,A.se);
		}
	}
	For(i,1,m) {
		int x,y;
		scanf("%d%d",&x,&y);
		int an=cal(root[x],1,n,y);
		printf("%d\n",an==N?-1:an);
	}
	return 0;
}