// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 1010
using namespace std;
int to[N],cap[N],vis[N],in[N];
int main()
{
	int n,m,a,b,c;
	scanf("%d%d",&n,&m);
	while ( m-- ) {
		scanf("%d%d%d",&a,&b,&c);
		to[a]=b;
		cap[a]=c;
		in[b]=1;
	}
	vector<int> sol;
	for ( int i=1; i<=n; i++ ) {
		if ( vis[i] || in[i] || !to[i] ) continue;
		int sml=cap[i],j;
		for ( j=i; to[j]; j=to[j] ) {
			sml=min(sml,cap[j]);
			vis[j]=1;
		}
		vis[j]=1;
		sol.push_back(i);
		sol.push_back(j);
		sol.push_back(sml);
	}
	printf("%d\n",(int)sol.size()/3);
	for ( int i=0; i<(int)sol.size(); i+=3 ) printf("%d %d %d\n",sol[i],sol[i+1],sol[i+2]);
	return 0;
}