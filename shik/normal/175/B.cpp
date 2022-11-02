// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
map<string,int> big;
vector<int> v;
int main()
{
	char s[100];
	int n,x;
	scanf("%d",&n);
	while ( n-- ) {
		scanf("%s %d",s,&x);
		big[s]=max(big[s],x);
	}
	n=SZ(big);
	FOR(it,big) v.push_back(it->second);
	sort(v.begin(),v.end());
	printf("%d\n",n);
	FOR(it,big) {
		x=(it->second);
		int r=n-(upper_bound(v.begin(),v.end(),x)-v.begin());
		if ( 2*r>n ) printf("%s noob",(it->first).c_str());
		else if ( 5*r>n ) printf("%s random",(it->first).c_str());
		else if ( 10*r>n ) printf("%s average",(it->first).c_str());
		else if ( 100*r>n ) printf("%s hardcore",(it->first).c_str());
		else printf("%s pro",(it->first).c_str());
		puts("");
	}
	return 0;
}