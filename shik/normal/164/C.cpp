// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define FN 514514
#define FM 514514
#define INF 1000000005
struct E {
	int id,k,c,w;
	E(){}
	E( int _id, int _k, int _c, int _w ):id(_id),k(_k),c(_c),w(_w){}
} es[FM];
struct Flow {
	int n,m,dis[FN],pre[FN];
	vector<int> e[FN];
	void init( int _n ) {
		n=_n; m=0;
		for ( int i=0; i<n; i++ ) e[i].clear();
	}
	void add( int id, int a, int b, int c, int w ) {
		e[a].push_back(m); es[m++]=E(id,b,c,w);
		e[b].push_back(m); es[m++]=E(-1,a,0,-w);
	}
	bool SPFA() {
		queue<int> q;
		for ( int i=0; i<n; i++ ) dis[i]=-INF;
		dis[0]=0; q.push(0);
		while ( !q.empty() ) {
			int p=q.front(); q.pop();
			FOR(it,e[p]) {
				E &ee=es[*it];
				if ( ee.c==0 || dis[p]+ee.w<=dis[ee.k] ) continue;
				dis[ee.k]=dis[p]+ee.w;
				pre[ee.k]=*it;
				q.push(ee.k);
			}
		}
		return dis[n-1]>0;
	}
	void solve( int shik ) {
		int cost=0;
		while ( SPFA() ) {
			int sml=INF;
			for ( int i=n-1; i; i=es[pre[i]^1].k ) sml=min(sml,es[pre[i]].c);
			cost+=sml*dis[n-1];
			for ( int i=n-1; i; i=es[pre[i]^1].k ) {
				es[pre[i]].c-=sml;
				es[pre[i]^1].c+=sml;
			}
		}
		int sol[1010]={};
		for ( int i=0; i<n; i++ ) FOR(it,e[i]) {
			E &ee=es[*it];
			if ( ee.c==0 && ee.id!=-1 ) sol[ee.id]=1;
		}
		for ( int i=0; i<shik; i++ ) printf("%d%c",sol[i],i==shik-1?'\n':' ');
	}
} flow;
#define N 1010
struct P {
	int s,t,c;
	void read() {
		scanf("%d%d%d",&s,&t,&c);
		t+=s;
	}
} p[N];
int l[2*N],nl;
int get( int x ) { return lower_bound(l,l+nl,x)-l+1; }
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for ( int i=0; i<n; i++ ) p[i].read();
	for ( int i=0; i<n; i++ ) {
		l[nl++]=p[i].s;
		l[nl++]=p[i].t;
	}
	sort(l,l+nl); nl=unique(l,l+nl)-l;
	for ( int i=0; i<n; i++ ) {
		p[i].s=get(p[i].s);
		p[i].t=get(p[i].t);
	}
	flow.init(nl+2);
	for ( int i=0; i<=nl; i++ ) flow.add(-1,i,i+1,m,0);
	for ( int i=0; i<n; i++ ) flow.add(i,p[i].s,p[i].t,1,p[i].c);
	flow.solve(n);
	return 0;
}