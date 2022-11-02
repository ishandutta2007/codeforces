// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 200010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
struct BIT {
	int dat[N];
	void ins( int x ) {
		x++;
		for ( int i=x; i<N; i+=i&-i ) dat[i]++;
	}
	int Q( int x ) {
		x++;
		int r=0;
		for ( int i=x; i; i-=i&-i ) r+=dat[i];
		return r;
	}
} bit[26];
int bye[N];
vector<int> app[26];
int main()
{
	int k,l,n,p;
	char s[110],c;
	scanf("%d%s",&k,s);
	l=strlen(s);
	for ( int i=0; i<k*l; i++ ) app[s[i%l]-'a'].push_back(i);
	scanf("%d",&n);
	while ( n-- ) {
		scanf("%d %c",&p,&c); p--;
		int L=0,R=SZ(app[c-'a'])-1;
		while ( L!=R ) {
			int M=(L+R)/2;
			if ( M-bit[c-'a'].Q(M)>=p ) R=M;
			else L=M+1;
		}
		bye[app[c-'a'][L]]=1;
		bit[c-'a'].ins(L);
	}
	for ( int i=0; i<k*l; i++ ) if ( !bye[i] ) putchar(s[i%l]);
	puts("");
	return 0;
}