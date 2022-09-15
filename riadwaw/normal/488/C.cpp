#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

#ifdef ONLINE_JUDGE
#define OJ 1
#else
#define OJ 0
#endif

//#define dd				double
#define ll 				int
#define pb 				push_back
#define mp 				make_pair
#define X				first
#define Y				second
#define forn( i, n ) 	for( ll i = 0; i < (ll) (n); i ++ )
#define endl 			'\n'

#define TIMESTAMP fprintf(stderr, "Execution time: %.3lf s.\n", (double)clock()/CLOCKS_PER_SEC)

//class C_ {}; template < typename T > C_& operator << ( C_& __m, const T& __s ) { if( !OJ ) cerr << "\E[91m" << __s << "\E[0m"; return __m; }
//C_ merr;

struct __s { __s() {
		//srand( time( NULL ) );
		//freopen( "input.txt", "r", stdin ); //freopen( "output.txt", "w", stdout );
		if( OJ ) { ios_base::Init i; cin.sync_with_stdio( 0 ); cin.tie( 0 ); } 
	} ~__s() { 
		if( !OJ ) TIMESTAMP; 
		ll n; cin >> n; 
	} 
} __S;



int main( void ) {
	ll n;
	ll ans = 1000000000;
	ll hY, aY, dY;
	ll hM, aM, dM;
	ll h, a, d;
	cin >> hY >> aY >> dY;
	cin >> hM >> aM >> dM;
	cin >> h >> a >> d;
	ll aaa = max( aY, dM + hM );
	ll ddd = max( dY, aM );
	for( ll aa = aY; aa <= aaa; aa ++ ) {
		for( ll dd = dY; dd <= ddd; dd ++ ) {
			for( ll hh = hY; hh <= 10000; hh ++ ) {
				if( aa <= dM )
					continue;
				ll cc = aM - dd;
				ll res = ( aa - aY ) * a + ( dd - dY ) * d + ( hh - hY ) * h;
				if( cc > 0 ) {
					ll bb = aa - dM;
					ll b = ( hM + bb - 1 ) / bb;
					ll c = ( hh + cc - 1 ) / cc;
					if( b < c) {{if( res < ans )
					ans = res;break;}}
				}
				else  {if( res < ans )
					ans = res;break;}
			}
		}
	}
	cout << ans << endl;
	return 0;	
}