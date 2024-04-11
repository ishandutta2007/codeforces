#include <bits/stdc++.h>

using namespace std;

const int MAXN = 101;

map < string, int > st;

vector < string > vec;

bool lim[MAXN][MAXN], f[MAXN], done;

string rmsg[MAXN], msg, chose[MAXN];

int n, m, g;

inline void push(string &s) { st[ s ] = vec.size(); vec.push_back( s ); }

inline int only(bool *x)
{
	int p = -2;
	for( int i = 0 ; i < n ; i++ ) if( !x[ i ] )
	{
		if( p < 0 ) p = i;
		else return -1;
	}
	return p;
}

inline void make()
{
	for( int i = 1 ; i <= m ; i++ ) if( chose[ i ] == "" )
		for( int j = 0 ; j < n ; j++ ) if( !lim[ i ][ j ] )
		{
			chose[ i ] = vec[ j ];
			lim[ i + 1 ][ j ] = 1;
			break;
		}
}

inline void print(int x)
{
	bool flag = false;
	if( f[ x ] ) { cout << rmsg[ x ] << endl; return ; }
	for( int i = 0 ; i < rmsg[ x ].length(); i++ )
	{
		if( rmsg[ x ][ i ] == '?' && !flag ) flag = true, cout << chose[ x ];
		else cout << rmsg[ x ][ i ];
	}
	putchar( 10 );
}

inline void solve()
{
	string tmp;
	memset( f, 0, sizeof f );
	memset( lim, 0, sizeof lim );
	vec.clear(); st.clear();
	scanf( "%d", &n );
	for( int i = 1 ; i <= n ; i++ )
		cin >> tmp, push( tmp );
	scanf( "%d", &m );
	for( int i = 1 ; i <= m ; i++ )
	{
		msg = "";
		while( msg == "" ) getline( cin, msg );
		rmsg[ i ] = msg;
		bool appeared = false;
		for( int j = 0 ; j < msg.size() ; j++ )
			if( !isalpha( msg[ j ] ) && !isdigit( msg[ j ] ) )
			{
				if( msg[ j ] == '?' ) msg[ j ] = appeared ? ' ' : '?';
				else if( msg[ j ] == ':' ) appeared = true, msg[ j ] = ' ';
				else msg[ j ] = ' ';
			}
		stringstream ss( msg );
		string a, b;
		ss >> a;
		if( a == "?" ) a = "";
		else f[ i ] = true;
		chose[ i ] = a;
		while( ss >> b )
		{
			if( st.find( b ) != st.end() )
			{
				if( a == b ) { printf( "Impossible\n" ); goto end; }
				else if( a == "" ) lim[ i ][ st[ b ] ] = 1;
			}
		}	
	}
	while( true )
	{
		for( int i = 1 ; i <= m ; i++ ) if( chose[ i ] == "" )
		{
			if( i > 1 && chose[ i - 1 ] != "" ) lim[ i ][ st[ chose[ i - 1 ] ] ] = 1;
			if( i < m && chose[ i + 1 ] != "" ) lim[ i ][ st[ chose[ i + 1 ] ] ] = 1;
		}
		done = true;
		for( int i = 1 ; i <= m ; i++ ) if( chose[ i ] == "" )
		{
			g = only( lim[ i ] );
			if( g == -2 ) { printf( "Impossible\n" ); goto end; }
			else if( g == -1 ) continue;
			else done = false, chose[ i ] = vec[ g ];
		}
		if( done ) { make(); break; }
	}
	for( int i = 1 ; i <= m ; i++ ) print( i );
	end: ;
}

int main()
{
	int T;
	scanf( "%d", &T );
	while( T-- ) solve();
	return 0;
}