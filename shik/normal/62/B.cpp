// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 2000010
using namespace std;
vector<int> lst[130];
int len;
char s[N],t[N];
int cal( int pos, vector<int> &v ) {
	if ( v.empty() ) return len;
	if ( pos>=v.back() ) return pos-v.back();
	if ( pos<=v.front() ) return v.front()-pos;
	int ret=len,tmt=lower_bound(v.begin(),v.end(),pos)-v.begin();
	if ( tmt<(int)v.size() ) ret=min(ret,v[tmt]-pos);
	if ( tmt>0 ) ret=min(ret,pos-v[tmt-1]);
	return ret;
}
int main()
{
	int n,m,i;
	long long ans;
	scanf("%d%d%s",&n,&m,s);
	for ( i=0; i<m; i++ ) lst[(int)s[i]].push_back(i);
	while ( n-- ) {
		scanf("%s",t);
		len=strlen(t);
		ans=0;
		for ( i=0; i<len; i++ ) ans+=cal(i,lst[(int)t[i]]);	
		printf("%I64d\n",ans);
	}
	return 0;
}