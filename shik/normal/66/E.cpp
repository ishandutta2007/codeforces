// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>
#include <vector>
#define fr q.front()
#define bk q.back()
#define N 200010
using namespace std;
int n,s1[N],s2[N],tmt[N];
deque<int> q;
void cal_1( int *s ) {
	q=deque<int>();
	for ( int i=0; i<n; i++ ) {
		while ( !q.empty() && s[fr]>=s[i] ) q.pop_front();
		q.push_front(i);	
	}
	for ( int i=0; i<n; i++ ) {
		if ( s[bk]>=s[i] ) tmt[i+1]=1;
		if ( bk==i ) q.pop_back();
		while ( !q.empty() && s[fr]>=s[i] ) q.pop_front();
		q.push_front(i);
	}
}
void cal_2( int *s ) {
	q=deque<int>();
	for ( int i=0; i<n; i++ ) {
		while ( !q.empty() && s[fr]>=s[i] ) q.pop_front();
		q.push_front(i);	
	}
	for ( int i=0; i<n; i++ ) {
		if ( s[bk]>=s[i] ) tmt[n-i]=1;
		if ( bk==i ) q.pop_back();
		while ( !q.empty() && s[fr]>=s[i] ) q.pop_front();
		q.push_front(i);
	}
}
int main()
{
	static int a[N],b[N],c[N];
	int i,ans=0;
	vector<int> sol;
	scanf("%d",&n);
	for ( i=1; i<=n; i++ ) scanf("%d",a+i);
	for ( i=1; i<=n; i++ ) scanf("%d",b+i);
	for ( i=1; i<=n; i++ ) c[i]=a[i]-b[i];
	for ( i=1; i<=n; i++ ) s1[i]=s1[i-1]+c[i];
	cal_1(s1);
	for ( i=1; i<=n; i++ ) c[i]=a[i]-b[i-1==0?n:i-1];
	for ( i=1; i<=n; i++ ) s2[i]=s2[i-1]+c[n-i+1];
	cal_2(s2);
	for ( i=1; i<=n; i++ )
		if ( tmt[i] ) sol.push_back(i);
	ans=(int)sol.size();
	printf("%d\n",ans);
	for ( i=0; i<ans; i++ ) printf("%d%c",sol[i],i==ans-1?'\n':' ');
	return 0;
}