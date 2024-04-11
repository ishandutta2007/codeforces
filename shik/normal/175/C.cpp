// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define N 110
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
struct P {
	int k,c;
	void read() { scanf("%d%d",&k,&c); }
} p[N];
bool operator <( P a, P b ) { return a.c<b.c; }
typedef long long LL;
int main()
{
	int n,t; LL x[N]={},ans=0;
	scanf("%d",&n);
	for ( int i=0; i<n; i++ ) p[i].read();
	sort(p,p+n);
	scanf("%d",&t);
	for ( int i=1; i<=t; i++ ) cin>>x[i];
	x[++t]=(1LL<<60);
	for ( int i=1,j=0; i<=t; i++ ) {
		LL c=x[i]-x[i-1];
		while ( j<n && p[j].k<=c ) {
			ans+=1LL*i*p[j].k*p[j].c;
			c-=p[j].k;
			j++;
		}
		if ( j<n ) {
			ans+=1LL*i*c*p[j].c;
			p[j].k-=c;
		}
	}
	cout<<ans<<endl;
	return 0;
}