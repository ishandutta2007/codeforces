#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
int n , q ;
string a ;

class Tree {
public :
    int tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( IR < pos || pos < IL ) { return ; }
        tr[ where ] += val ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , val ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        }
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( CURL > CURR ) { return 0 ; }
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) {
            return tr[ where ] ;
        }
        int mid = ( IL + IR ) / 2 ;
        return query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
    }
    int get_fst ( int where , int IL , int IR ) {
        if ( tr[ where ] == 0 ) { return -1 ; }
        if ( IL == IR ) { return IL ; }
        int mid = ( IL + IR ) / 2 ;
        if ( tr[ 2 * where ] > 0 ) { return get_fst ( 2 * where , IL , mid ) ; }
        return get_fst ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    int get_lst ( int where , int IL , int IR ) {
        if ( tr[ where ] == 0 ) { return -1 ; }
        if ( IL == IR ) { return IL ; }
        int mid = ( IL + IR ) / 2 ;
        if ( tr[ 2 * where + 1 ] > 0 ) { return get_lst ( 2 * where + 1 , mid + 1 , IR ) ; }
        return get_lst ( 2 * where , IL , mid ) ;
    }
};
Tree rock , paper , scissors ;

void proc_letter ( char c , int pos , int coef ) {
    if ( c == 'R' ) {
        rock.update ( 1 , 1 , n , pos , coef ) ;
    }
    else if ( c == 'P' ) {
        paper.update ( 1 , 1 , n , pos , coef ) ;
    }
    else {
        scissors.update ( 1 , 1 , n , pos , coef ) ;
    }
}
int ans ( ) {
    int fst_rock = rock.get_fst ( 1 , 1 , n ) , lst_rock = rock.get_lst ( 1 , 1 , n ) ;
    int fst_paper = paper.get_fst ( 1 , 1 , n ) , lst_paper = paper.get_lst ( 1 , 1 , n ) ;
    int fst_scissors = scissors.get_fst ( 1 , 1 , n ) , lst_scissors = scissors.get_lst ( 1 , 1 , n ) ;

    int ret = 0 ;
    if ( fst_paper == -1 ) {
        ret += rock.query ( 1 , 1 , n , 1 , n ) ;
    }
    else {
        if ( fst_scissors > 0 ) {
            ret += rock.query ( 1 , 1 , n , fst_scissors , lst_scissors ) ;
            ret += rock.query ( 1 , 1 , n , 1 , min ( fst_paper , fst_scissors ) ) ;
            ret += rock.query ( 1 , 1 , n , max ( lst_paper , lst_scissors ) , n ) ;
        }
    }

    if ( fst_scissors == -1 ) {
        ret += paper.query ( 1 , 1 , n , 1 , n ) ;
    }
    else {
        if ( fst_rock > 0 ) {
            ret += paper.query ( 1 , 1 , n , fst_rock , lst_rock ) ;
            ret += paper.query ( 1 , 1 , n , 1 , min ( fst_scissors , fst_rock ) ) ;
            ret += paper.query ( 1 , 1 , n , max ( lst_scissors , lst_rock ) , n ) ;
        }
    }

    if ( fst_rock == -1 ) {
        ret += scissors.query ( 1 , 1 , n , 1 , n ) ;
    }
    else {
        if ( fst_paper > 0 ) {
            ret += scissors.query ( 1 , 1 , n , fst_paper , lst_paper ) ;
            ret += scissors.query ( 1 , 1 , n , 1 , min ( fst_rock , fst_paper ) ) ;
            ret += scissors.query ( 1 , 1 , n , max ( lst_rock , lst_paper ) , n ) ;
        }
    }
    
    return ret ;
}

void input ( ) {
    cin >> n >> q ;
    cin >> a ;
    rock.init ( 1 , 1 , n ) ;
    paper.init ( 1 , 1 , n ) ;
    scissors.init ( 1 , 1 , n ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        proc_letter ( a[ i ] , i + 1 , 1 ) ;
    }
}

void solve ( ) {
    int pos ;
    char c ;
    cout << ans ( ) << "\n" ;
    while ( q -- ) {
        cin >> pos >> c ;
        proc_letter ( a[ pos - 1 ] , pos , -1 ) ;
        a[ pos - 1 ] = c ;
        proc_letter ( a[ pos - 1 ] , pos , 1 ) ;
        cout << ans ( ) << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}