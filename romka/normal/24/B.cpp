#include <cstdio>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <memory.h>
#include <string>
#include <iostream>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;

const int PNT[] = { 25, 18, 15, 12, 10, 8, 6, 4, 2, 1 };

int t, n;
string s;
int places[1010][55];
map<string,int> mid;
int kid;
string name[1010];
int p[1010];
int points[1010];

inline int getid( string& s )
{
	if ( mid.find( s ) == mid.end() )
	{
		name[kid] = s;
		return mid[s] = kid++;
	}
	return mid[s];
}

bool cmp1( int i, int j )
{
	if ( points[i] > points[j] ) return true;
	if ( points[i] < points[j] ) return false;
	
	forn( pl, 50 )
	{
		if ( places[i][pl] > places[j][pl] ) return true;
		if ( places[i][pl] < places[j][pl] ) return false;
	}
	
	return false;
}

bool cmp2( int i, int j )
{
		if ( places[i][0] > places[j][0] ) return true;
		if ( places[i][0] < places[j][0] ) return false;
		
	if ( points[i] > points[j] ) return true;
	if ( points[i] < points[j] ) return false;
	
	forn( pl, 50 )
	{
		if ( places[i][pl] > places[j][pl] ) return true;
		if ( places[i][pl] < places[j][pl] ) return false;
	}
	
	return false;
}

int main()
{
	scanf( "%d", &t );
	forn( q,t )
	{
		scanf( "%d", &n );
		forn( i,n )
		{
			cin >> s;
			int id = getid( s );
			places[id][i]++;
			if ( i < 10 ) points[id] += PNT[i];
		}							
	}
	
	forn( i, kid ) p[i] = i;
	
	sort( p, p+kid, cmp1 );
	printf( "%s\n", name[ p[0] ].c_str() );
	
	sort( p, p+kid, cmp2 );
	printf( "%s\n", name[ p[0] ].c_str() );
}