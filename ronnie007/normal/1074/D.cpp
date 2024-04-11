#include<bits/stdc++.h>
using namespace std ;

#define MAXN 800007

int q ;
int prv[ MAXN ][ 30 ] ;
int rnk[ MAXN ][ 30 ] ;

map < int , int > w1 , w2 ;
int lst_ans ;

int find ( int x , int bit ) {
    if ( prv[ x ][ bit ] == -1 ) { return x ; }
    int y = find ( prv[ x ][ bit ] , bit ) ;
    prv[ x ][ bit ] = y ;
    return y ;
}

void unite ( int x , int y , int bit ) {
    int k1 = find ( x , bit ) ;
    int k2 = find ( y , bit ) ;
    if ( k1 != k2 ) {
        if ( rnk[ k1 ][ bit ] >= rnk[ k2 ][ bit ] ) {
            rnk[ k1 ][ bit ] += ( rnk[ k1 ][ bit ] == rnk[ k2 ][ bit ] ) ;
            prv[ k2 ][ bit ] = k1 ;
        }
        else {
            prv[ k1 ][ bit ] = k2 ;
        }
    }
}

void input ( ) {
    scanf ( "%d" , &q ) ;
    for ( int i = 0 ; i <= 4 * q ; ++ i ) {
        for ( int j = 0 ; j < 30 ; ++ j ) {
            prv[ i ][ j ] = -1 ;
            rnk[ i ][ j ] = 0 ; 
        }
    }
}

void solve ( ) {
    int type , l , r , x ;
    int tpid = 1 ;
    while ( q -- ) {
        scanf ( "%d" , &type ) ;
        if ( type == 1 ) {
            scanf ( "%d%d%d" , &l , &r , &x ) ;
            l ^= lst_ans ; r ^= lst_ans ; x ^= lst_ans ;
            if ( l > r ) { swap ( l , r ) ; }
            ++ r ;
            if ( w1.find ( l ) == w1.end ( ) ) {
                w1[ l ] = tpid ++ ;
                w2[ l ] = tpid ++ ;
            }
            if ( w1.find ( r ) == w1.end ( ) ) {
                w1[ r ] = tpid ++ ;
                w2[ r ] = tpid ++ ; 
            }
            bool bad = false ;
            int left1 , left2 ;
            int right1 , right2 ;
            left1 = w1[ l ] ; left2 = w2[ l ] ;
            right1 = w1[ r ] ; right2 = w2[ r ] ;
            
            for ( int i = 0 ; i < 30 ; ++ i ) {
                if ( ( x & (1<<i) ) > 0 ) {
                    if ( find ( left1 , i ) == find ( right1 , i ) ) {
                        bad = true ;
                        break ;
                    }
                }
                else {
                    if ( find ( left1 , i ) == find ( right2 , i ) ) {
                        bad = true ;
                        break ;
                    }
                }
            }
            if ( bad == true ) { continue ; }
            for ( int i = 0 ; i < 30 ; ++ i ) {
                if ( ( x & (1<<i) ) == 0 ) {
                    unite ( left1 , right1 , i ) ;
                    unite ( left2 , right2 , i ) ;
                }
                else {
                    unite ( left1 , right2 , i ) ;
                    unite ( left2 , right1 , i ) ;
                }
            }
        }
        else {
            scanf ( "%d%d" , &l , &r ) ;
            l ^= lst_ans ; r ^= lst_ans ;
            if ( l > r ) { swap ( l , r ) ; }
            ++ r ;
            if ( w1.find ( l ) == w1.end ( ) ) {
                w1[ l ] = tpid ++ ;
                w2[ l ] = tpid ++ ;
            }
            if ( w1.find ( r ) == w1.end ( ) ) {
                w1[ r ] = tpid ++ ;
                w2[ r ] = tpid ++ ; 
            }
            int left1 , left2 ;
            int right1 , right2 ;
            left1 = w1[ l ] ; left2 = w2[ l ] ;
            right1 = w1[ r ] ; right2 = w2[ r ] ;
            int ans = 0 ;
            bool fl = false ;
            for ( int i = 0 ; i < 30 ; ++ i ) {
                if ( find ( left1 , i ) != find ( right1 , i ) && find ( left1 , i ) != find ( right2 , i ) ) {
                    fl = true ;
                    break ;
                }
                else {
                    if ( find ( left1 , i ) == find ( right2 , i ) ) {
                        ans += (1<<i) ;
                    }
                }
            }
            if ( fl == true ) {
                printf ( "-1\n" ) ;
                lst_ans = 1 ;
            }
            else {
                printf ( "%d\n" , ans ) ;
                lst_ans = ans ;
            }
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}