// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef pair<int,int> PII;
#define X first
#define Y second
#define MP make_pair
set<PII> ok;
map<PII,int> dis;
int main()
{
	int n,x0,y0,x1,y1,r,a,b;
	scanf("%d%d%d%d%d",&x0,&y0,&x1,&y1,&n);
	while ( n-- ) {
		scanf("%d%d%d",&r,&a,&b);
		for ( int i=a; i<=b; i++ ) ok.insert(MP(r,i));
	}
	queue<PII> q;
	dis[MP(x0,y0)]=0;
	q.push(MP(x0,y0));
	while ( !q.empty() ) {
		int x=q.front().X;
		int y=q.front().Y;
		int d=dis[MP(x,y)];
		q.pop();
		for ( int i=-1; i<=1; i++ ) for ( int j=-1; j<=1; j++ ) {
			PII np=MP(x+i,y+j);
			if ( dis.count(np) || !ok.count(np) ) continue;
			q.push(np);
			dis[np]=d+1;
		}
	}
	if ( !dis.count(MP(x1,y1)) ) puts("-1");
	else printf("%d\n",dis[MP(x1,y1)]);
	return 0;
}