// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <functional>
#define N 100010
using namespace std;
int a[N],ans[N];
vector<pair<int,int> > stk;
int main()
{
	int n;
	scanf("%d",&n);
	for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
	for ( int i=n; i>0; i-- ) {
		if ( stk.empty() || a[i]<=stk.back().first ) ans[i]=-1;
		else ans[i]=lower_bound(stk.begin(),stk.end(),make_pair(a[i],i),greater_equal<pair<int,int> >())->second - i - 1;
		if ( stk.empty() || a[i]<stk.back().first ) stk.push_back(make_pair(a[i],i));
	}
	for ( int i=1; i<=n; i++ ) printf("%d%c",ans[i],i==n?'\n':' ');
	return 0;
}