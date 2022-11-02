// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>
#define N 100010
using namespace std;
int num[N];
deque<int> q1,q2;
int st[N],ed[N],cnt,big;
int main()
{
	int n,k,i,tmt=1;
	scanf("%d%d",&n,&k);
	for ( i=1; i<=n; i++ ) scanf("%d",num+i);
	for ( i=1; i<=n; i++ ) {
		while ( !q1.empty() && num[i]-num[q1.back()]>k ) { tmt=max(tmt,q1.back()+1); q1.pop_back(); }
		while ( !q2.empty() && num[q2.back()]-num[i]>k ) { tmt=max(tmt,q2.back()+1); q2.pop_back(); }
		while ( !q1.empty() && num[q1.front()]>num[i] ) q1.pop_front();
		while ( !q2.empty() && num[q2.front()]<num[i] ) q2.pop_front();
		q1.push_front(i); q2.push_front(i);
		if ( i-tmt+1>big ) cnt=0;
		if ( i-tmt+1>=big ) {
			big=i-tmt+1;
			st[cnt]=tmt;
			ed[cnt]=i;
			cnt++;
		}
	}
	printf("%d %d\n",big,cnt);
	for ( i=0; i<cnt; i++ ) printf("%d %d\n",st[i],ed[i]);
	return 0;
}