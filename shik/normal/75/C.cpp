// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int a,b,g;
	vector<int> v;
	scanf("%d%d",&a,&b);
	g=__gcd(a,b);
	for ( int i=1; i*i<=g; i++ ) {
		if ( g%i ) continue;
		v.push_back(i);
		if ( i!=g/i ) v.push_back(g/i);
	}
	sort(v.begin(),v.end());
	int q,l,r;
	scanf("%d",&q);
	while ( q-- ) {
		scanf("%d%d",&l,&r);
		int p=*(upper_bound(v.begin(),v.end(),r)-1);
		if ( p<l ) puts("-1");
		else printf("%d\n",p);
	}
	return 0;
}