// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1010
using namespace std;
struct S {
	int L,R;
	void read() {
		scanf("%d%d",&L,&R);
		if ( L>R ) swap(L,R);
	}
} seg[N];
bool cp( S a, S b ) { return a.R<b.R; }
int sol[N];
int main()
{
	int n,i,ans=0,pre=-9999999;
	scanf("%d",&n);
	for ( i=0; i<n; i++ ) seg[i].read();
	sort(seg,seg+n,cp);
	for ( i=0; i<n; i++ ) {
		if ( seg[i].L<=pre ) continue;
		sol[ans++]=seg[i].R;
		pre=seg[i].R;
	}
	printf("%d\n",ans);
	for ( i=0; i<ans; i++ ) printf("%d%c",sol[i],i==ans-1?'\n':' ');
	return 0;
}