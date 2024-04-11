// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define PB push_back
#define N 1010
#define INF 9999999999999999LL
using namespace std;
typedef long long LL;
struct E {
	int k,c;
	E(){}
	E( int _k, int _c ):k(_k),c(_c){}
};
vector<E> e[N];
int n,w[N][N],tt[N],cc[N];
void pre_cal( int st ) {
	LL d[N];
	fill(d,d+N,INF);
	queue<int> q;
	bool inq[N]={};
	q.push(st); d[st]=0;
	while ( !q.empty() ) {
		int p=q.front(); q.pop(); inq[p]=0;
		for ( vector<E>::iterator it=e[p].begin(); it!=e[p].end(); it++ )
			if ( d[p]+it->c < d[it->k] ) {
				d[it->k]=d[p]+it->c;
				if ( !inq[it->k] ) { q.push(it->k); inq[it->k]=1; }
			}
	}
	for ( int i=1; i<=n; i++ )
		if ( d[i]<=tt[st] ) w[st][i]=cc[st]; 
}
void solve( int st, int ed ) {
	LL d[N];
	fill(d,d+N,INF);
	queue<int> q;
	bool inq[N]={};
	q.push(st); d[st]=0;
	while ( !q.empty() ) {
		int p=q.front(); q.pop(); inq[p]=0;
		for ( int i=1; i<=n; i++ ) {
			if ( w[p][i]==-1 ) continue;
			if ( d[p]+w[p][i]<d[i] ) {
				d[i]=d[p]+w[p][i];
				if ( !inq[i] ) { q.push(i); inq[i]=1; }
			}
		}
	}
	printf("%I64d\n",d[ed]==INF?-1LL:d[ed]);
}
int main()
{
	memset(w,-1,sizeof(w));
	int m,st,ed,a,b,c,i;
	scanf("%d%d",&n,&m);
	scanf("%d%d",&st,&ed);
	while ( m-- ) {
		scanf("%d%d%d",&a,&b,&c);
		e[a].PB(E(b,c));
		e[b].PB(E(a,c));
	}
	for ( i=1; i<=n; i++ ) scanf("%d%d",tt+i,cc+i);
	for ( i=1; i<=n; i++ ) pre_cal(i);
	solve(st,ed);
	return 0;
}