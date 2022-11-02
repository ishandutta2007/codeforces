#include <cstdio>
#include <cmath>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cstring>
#include <iostream>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
	string s;
	cin >> s;
	int ans = 0;
	forn( i, s.size() )
		for ( int j=1; j<s.size(); j++ )
		{
			string t = s.substr( i, j );
			if ( t.size() > ans ) {
			forn( q, (int)s.size()-(int)t.size()+1 ) if ( q != i )
				if ( s.substr( q, t.size() ) == t )
				{
					if ( t.size() > ans ) ans = t.size();
				}
			}
		}
	printf( "%d\n", ans );
}