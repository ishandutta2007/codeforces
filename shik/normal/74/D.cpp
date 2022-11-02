// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
struct Rng {
	int st,ed;
	Rng(){}
	Rng( int _st, int _ed ):st(_st),ed(_ed){}
} now;
inline bool operator <( const Rng &a, const Rng &b ) {
	if ( a.ed-a.st != b.ed-b.st ) return a.ed-a.st > b.ed-b.st;	
	return a.st>b.st;
}
set<Rng> q;
set<int> lst;
set<int>::iterator it,jt;
map<int,int> BIT;
int n;
void ins( int x, int k ) {
	for ( int i=x; i<=n; i+=i&-i ) BIT[i]+=k;
}
int Q( int x ) {
	int i,r=0;
	for ( i=x; i; i-=i&-i )
		if ( BIT.find(i)!=BIT.end() ) r+=BIT[i];
	return r;	
}
int Q( int a, int b ) { return Q(b)-Q(a-1); }
map<int,int> pos;
int main()
{
	int m,x,a,b;
	scanf("%d%d",&n,&m);
	q.insert(Rng(1,n));
	lst.insert(0);
	lst.insert(n+1);
	while ( m-- ) {
		scanf("%d",&x);
		if ( x==0 ) {
			scanf("%d%d",&a,&b);
			printf("%d\n",Q(a,b));
		} else {
			if ( pos[x]==0 ) {
				now=*q.begin();
				q.erase(now);
				int mid=(now.st+now.ed+1)/2;
				pos[x]=mid;
				lst.insert(mid);
				ins(mid,1);
				if ( now.st<=mid-1 ) q.insert(Rng(now.st,mid-1));
				if ( mid+1<=now.ed ) q.insert(Rng(mid+1,now.ed));
			} else {
				int pre,mid,nxt;
				mid=pos[x];
				it=jt=lst.find(mid);
				pre=*--it;
				nxt=*++jt;
				if ( pre+1<=mid-1 ) q.erase(Rng(pre+1,mid-1));
				if ( mid+1<=nxt-1 ) q.erase(Rng(mid+1,nxt-1));
				if ( pre+1<=nxt-1 ) q.insert(Rng(pre+1,nxt-1));
				lst.erase(mid);
				ins(mid,-1);
				pos[x]=0;	
			}
		}
	}
	return 0;
}