// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#define N 100010
using namespace std;
int fa[N],key[N],lch[N],rch[N],dep[N];
int n_leaf,lst[N],tmt[N];
double sum[N];
queue<int> q;
map<int,int> id;
int nxt( int x ) { return x>=lst[n_leaf-1]?-1:*upper_bound(lst,lst+n_leaf,x); }
int pre( int x ) { return x<=lst[0]?-1:*(lower_bound(lst,lst+n_leaf,x)-1); }
int main()
{
	int n,m,i,x,a,b,root;
	scanf("%d",&n);
	for ( i=1; i<=n; i++ ) scanf("%d%d",fa+i,key+i);
	for ( i=1; i<=n; i++ )
		if ( fa[i]!=-1 ) {
			if ( key[i]<key[fa[i]] ) lch[fa[i]]=i;
			else rch[fa[i]]=i;
		}
	for ( i=1; i<=n; i++ ) 
		if ( fa[i]==-1 ) root=i;
	for ( i=1; i<=n; i++ )
		if ( lch[i]==0 && rch[i]==0 ) lst[n_leaf++]=key[i];
	sort(lst,lst+n_leaf);
	q.push(root);
	while ( !q.empty() ) {
		int p=q.front(); q.pop();
		if ( p==root ) dep[p]=sum[p]=0;
		else {
			dep[p]=dep[fa[p]]+1;
			if ( p==lch[fa[p]] ) sum[p]=sum[fa[p]]+nxt(key[fa[p]]);
			else sum[p]=sum[fa[p]]+pre(key[fa[p]]);
		}
		if ( lch[p] ) q.push(lch[p]);
		if ( rch[p] ) q.push(rch[p]);
	}
	id[-1]=-1;
	for ( i=1; i<=n; i++ ) id[key[i]]=i;
	for ( i=0; i<n; i++ ) tmt[i]=key[i+1];
	sort(tmt,tmt+n);
	//for ( i=1; i<=n; i++ ) printf("%d: fa=%d, key=%d, lch=%d, rch=%d, sum=%g\n",i,fa[i],key[i],lch[i],rch[i],sum[i]);
	scanf("%d",&m);
	while ( m-- ) {
		scanf("%d",&x);
		a=id[x<tmt[0]?tmt[0]:*(lower_bound(tmt,tmt+n,x)-1)];
		b=id[x>tmt[n-1]?tmt[n-1]:*lower_bound(tmt,tmt+n,x)];
		if ( lch[a]==0 ) printf("%.10f\n",sum[a]/dep[a]);
		else printf("%.10f\n",sum[b]/dep[b]);
	}
	return 0;
}