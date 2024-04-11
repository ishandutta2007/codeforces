#include <cstdio>
#include <vector>
#include <utility>
#include <string>
#include <ctime>
#include <memory.h>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;

int n, r1, r2;
char name[55][128], s1[128], s2[128];

int gsc[55], gmi[55], p[55], id[55];

bool cmp( int i, int j )
{
	if ( p[i] > p[j] ) return true; else
	if ( p[i] < p[j] ) return false; else
		if ( gsc[i]-gmi[i] > gsc[j]-gmi[j] ) return true; else
		if ( gsc[i]-gmi[i] < gsc[j]-gmi[j] ) return false; else
			return gsc[i] > gsc[j];
}

int main()
{
	cin >> n;
	forn( i,n ) cin >> name[i];
	
	char ss[256];
	forn( i, n*(n-1)/2 )
	{
		scanf( "%s %d:%d", ss, &r1, &r2 );
		int pi = -1;
		forn( j, 1000 ) if ( ss[j] == '-' )
		{
			ss[j] = '\0';
			pi = j+1;
			break;
		}
		strcpy( s1, ss );
		strcpy( s2, ss+pi );
		//puts( s1 ); puts( s2 ); puts( "-----------------" );
		
		int id1 = -1, id2 = -1;
		forn( j,n )
		{
			if ( strcmp( name[j], s1 ) == 0 ) id1 = j;
			if ( strcmp( name[j], s2 ) == 0 ) id2 = j;
		}
		
		if ( r1 > r2 ) p[id1] += 3; else
		if ( r1 < r2 ) p[id2] += 3; else
		{
			p[id1]++;
			p[id2]++;
		}
		
		gsc[id1] += r1;
		gmi[id1] += r2;
		
		gsc[id2] += r2;
		gmi[id2] += r1;
	}
	
//	forn( i,n ) printf( "%d ", p[i] ); printf( "\n" );
	
	forn( i, n ) id[i] = i;
	sort( id, id+n, cmp );
	
//	forn( i,n ) printf( "%d ", id[i] ); printf( "\n" );
	
	vector<string> ans;
	forn( i, n/2 ) ans.pb( name[ id[i] ] );
	sort( ans.begin(), ans.end() );
	
	forn( i, ans.size() )
		puts( ans[i].c_str() );
}