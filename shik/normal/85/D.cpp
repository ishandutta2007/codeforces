// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LID (id*2+0)
#define RID (id*2+1)
#define ME node[id]
#define LCH node[LID]
#define RCH node[RID]
#define N 100010
using namespace std;
struct Seg_T {
	struct Node {
		int id,st,ed,sz; long long sum[5];
		Node(){}
		Node( int _id, int _st, int _ed ):id(_id),st(_st),ed(_ed) { sz=0; memset(sum,0,sizeof(sum)); }
		int mid() { return (st+ed)/2; }
	} node[4*N];
	void init( int id, int L, int R ) {
		node[id]=Node(id,L,R);
		if ( L>=R ) return;
		int M=(L+R)/2;
		init(LID,L,M);
		init(RID,M+1,R);
	}
	void adj( int id ) {
		ME.sz=LCH.sz+RCH.sz;
		for ( int i=0; i<5; i++ ) ME.sum[i]=LCH.sum[i]+RCH.sum[((i-LCH.sz)%5+5)%5];
	}
	void ins( int id, int key, int val ) {
		if ( ME.st==ME.ed ) {
			ME.sz=1;
			ME.sum[0]=val;
			return;
		}
		ins(key<=ME.mid()?LID:RID,key,val);
		adj(id);
	}
	void del( int id, int key ) {
		if ( ME.st==ME.ed ) {
			ME.sz=ME.sum[0]=0;
			return;
		}
		del(key<=ME.mid()?LID:RID,key);
		adj(id);
	}
} seg_t;
int n,lst[N];
int get_key( int x ) { return upper_bound(lst,lst+n,x)-lst; }
struct Q {
	char op[5];
	int x;
	void read() {
		scanf("%s",op);
		if ( op[0]!='s' ) scanf("%d",&x);
	}
	void solve() {
		if ( op[0]=='a' ) seg_t.ins(1,get_key(x),x);
		else if ( op[0]=='d' ) seg_t.del(1,get_key(x));
		else printf("%I64d\n",seg_t.node[1].sum[2]);
	}
} inp[N];
int main()
{
	int m,i;
	scanf("%d",&m);
	for ( i=0; i<m; i++ ) inp[i].read();
	for ( i=0; i<m; i++ ) 
		if ( inp[i].op[0]!='s' ) lst[n++]=inp[i].x;
	sort(lst,lst+n);
	n=unique(lst,lst+n)-lst;
	seg_t.init(1,1,n);
	for ( i=0; i<m; i++ ) inp[i].solve();
	return 0;
}