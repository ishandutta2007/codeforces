// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#define N 55
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
string s[N*N];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m,k,op,x,y;
	string id;
	cin>>n>>m>>k;
	while ( k-- ) {
		cin>>op;
		if ( op==1 ){
			cin>>x>>y>>id; x--; y--;
			for ( int i=x*m+y; i<n*m; i++ ) if ( s[i]=="" ) { s[i]=id; break; }
		} else {
			cin>>id;
			int flg=0;
			for ( int i=0; i<n*m&&!flg; i++ ) if ( s[i]==id ) {
				s[i]="";
				printf("%d %d\n",i/m+1,i%m+1);
				flg=1;
			}
			if ( !flg ) puts("-1 -1");
		}
	}
	return 0;
}