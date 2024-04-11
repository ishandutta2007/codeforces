#include<bits/stdc++.h>
using namespace std ;

pair < long long , long long > a , sr ;

long long k , add_atk , add_h ;

long long f ( long long mid ) {
    long long tot = a.first + add_h * mid ;
    long long cnt = ( tot + sr.second - 1 ) / sr.second ;
    long long dmg = a.second + add_atk * ( k - mid ) ;
    if ( cnt > ( sr.first + dmg - 1 ) / dmg ) { return sr.first + 5 ; }
    return cnt * dmg ;
}

void input ( ) {
    cin >> a.first >> a.second ;
    cin >> sr.first >> sr.second ;
    cin >> k >> add_atk >> add_h ;
}

void solve ( ) {
    long long mx = 0 ;
    for ( int i = 0 ; i <= k ; ++ i ) {
        mx = max ( mx , f ( i ) ) ;
    }
    if ( mx >= sr.first ) {
        cout << "YES\n" ;
        return ;
    }
    cout << "NO\n" ;
}

int main ( ) {
	ios_base :: sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	int t ; cin >> t ;
	while ( t -- ) {
		input ( ) ;
		solve ( ) ;
	}
	return 0 ;
}