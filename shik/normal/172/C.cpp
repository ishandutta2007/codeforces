// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define N 100010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int t[N],x[N];
int main()
{
	int n,m,tmt=0;
	scanf("%d%d",&n,&m);
	for ( int i=0; i<n; i++ ) scanf("%d%d",t+i,x+i);
	for ( int i=0,j=0; i<n; i=j ) {
		map<int,int> cnt,ans;
		for ( j=i; j<n&&j<i+m; j++ ) cnt[x[j]]++;
		int np=0,nt=max(tmt,t[j-1]);
		FOR(it,cnt) {
			nt+=it->first-np;
			np=it->first;
			ans[it->first]=nt;
			nt+=1+it->second/2;
		}
		tmt=nt+np;
		for ( j=i; j<n&&j<i+m; j++ ) printf("%d%c",ans[x[j]],j==n-1?'\n':' ');
	}
	return 0;
}