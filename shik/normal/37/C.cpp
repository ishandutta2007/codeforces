// by shik
#include <cstdio>
#include <algorithm>
#include <vector>
#define N 1010
using namespace std;
struct W { int id,len; vector<int> v; void read( int _id ) { scanf("%d",&len); id=_id; } } w[N];
bool cp_len( W a, W b ) { return a.len<b.len; }
bool cp_id( W a, W b ) { return a.id<b.id; }
void print( vector<int> &v ) {
	for ( vector<int>::iterator it=v.begin(); it!=v.end(); it++ ) printf("%d",*it);
	puts("");
}
bool chk( vector<int> &v ) {
	for ( int i=(int)v.size()-1; i>0; i-- )
		while ( v[i]>=2 ) { v[i]-=2; v[i-1]++; }
	return v[0]<2;
}
int main()
{
	vector<int> now;
	int n,i;
	scanf("%d",&n);
	for ( i=0; i<n; i++ ) w[i].read(i);
	sort(w,w+n,cp_len);
	for ( i=0; i<n; i++ ) {
		while ( (int)now.size()<w[i].len ) now.push_back(0);
		if ( !chk(now) ) break;
		w[i].v=now;
		now[w[i].len-1]++;
	}
	if ( i<n ) puts("NO");
	else {
		puts("YES");
		sort(w,w+n,cp_id);
		for ( i=0; i<n; i++ ) print(w[i].v);	
	}
	return 0;
}