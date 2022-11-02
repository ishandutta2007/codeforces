// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define PB push_back
using namespace std;
typedef long long LL;
typedef vector<LL> VLL;
VLL lst;
bool chk( LL x ) {
	int c4=0,c7=0;
	while ( x ) {
		if ( x%10==4 ) c4++;
		else if ( x%10==7 ) c7++;
		else return 0;
		x/=10;
	}
	return c4==c7;
}
void go( LL x ) {
	if ( x>100000000000LL ) return;
	if ( x>0 && chk(x) ) lst.PB(x);
	go(x*10+4);
	go(x*10+7);
}
void BFS() {
	queue<LL> q;
	q.push(0);
	while ( !q.empty() ) {
		LL p=q.front(); q.pop();
		if ( p>1000000000000LL ) return;
		if ( p>0 && chk(p) ) lst.PB(p);
		q.push(p*10+4);
		q.push(p*10+7);
	}
}
int main()
{
	BFS();
	sort(lst.begin(),lst.end());
	LL n;
	scanf("%I64d",&n);
	printf("%I64d\n",*lower_bound(lst.begin(),lst.end(),n));
	return 0;
}