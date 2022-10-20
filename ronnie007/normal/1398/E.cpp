#include<bits/stdc++.h>
using namespace std ;

#define inf 1000000007
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct node {
    int val , br , prior ;
    long long sm ;
    node *pl , *pr ;
    node ( int x , int y ) {
        this->val = x ;
        this->sm = x ;
        this->prior = y ;
        this->br = 1 ;
        this->pl = this->pr = NULL ;
    }
};

int get_sz ( node *w ) {
    if ( w == NULL ) { return 0 ; }
    return ( w->br ) ;
}

long long get_sm ( node *w ) {
    if ( w == NULL ) { return 0 ; }
    return w->sm ;
}

void update ( node *arg ) {
    if ( arg == NULL ) { return ; }
    arg->br = 1 + get_sz ( arg->pl ) + get_sz ( arg->pr ) ;
    arg->sm = get_sm ( arg->pl ) + get_sm ( arg->pr ) + arg->val ;
}

void split ( node *w , node * &l , node * &r , int sr ) {
    if ( w == NULL ) { l = r = NULL ; return ; }
    if ( w->val <= sr ) {
        split ( w->pr , w->pr , r , sr ) ;
        l = w ;
        update ( l ) ;
    }
    else {
        split ( w->pl , l , w->pl , sr ) ;
        r = w ;
        update ( r ) ;
    }
}

void merge ( node * &w , node *l , node *r ) {
    if ( l == NULL && r == NULL ) { w = NULL ; return ; }
    if ( l == NULL ) { w = r ; return ; }
    if ( r == NULL ) { w = l ; return ; }
    if ( l->prior > r->prior ) {
        merge ( l->pr , l->pr , r ) ;
        w = l ;
        update ( w ) ;
    }
    else {
        merge ( r->pl , l , r->pl ) ;
        w = r ;
        update ( w ) ;
    }
}


long long getk ( node *w , int x ) {
    if ( get_sz ( w ) <= x ) { return get_sm ( w ) ; }
    int aux = get_sz ( w->pr ) ;
    if ( x <= aux ) { return getk ( w->pr , x ) ; }
    else {
        return w->val + get_sm ( w->pr ) + getk ( w->pl , x - aux - 1 ) ;
    }
}

node *root ;

void add ( int x ) {
    node *u1 , *u2 ;
    //u1 = u2 = NULL ;
    split ( root , u1 , u2 , x ) ;
    node *aux = new node ( x , rng ( ) ) ;
    merge ( u1 , u1 , aux ) ;
    update ( u1 ) ;
    merge ( root , u1 , u2 ) ;
    update ( root ) ;
}
void del ( int x ) {
    node *u1 , *u2 , *u3 ;
    u1 = u2 = u3 = NULL ;
    split ( root , u1 , u2 , x - 1 ) ;
    update ( u1 ) ;
    update ( u2 ) ;
    split ( u2 , u3 , u2 , x ) ;
    update ( u3 ) ;
    update ( u2 ) ;
    merge ( root , u1 , u2 ) ;
    update ( root ) ;
}

map < int , int > fire , lightning ;

void input ( ) {
    root = NULL ;
}

void solve ( ) {
    int n ;
    cin >> n ;
    int cnt = 0 ;
    long long ans ;
    while ( n -- ) {
        int type , x ;
        cin >> type >> x ;
        if ( type == 0 ) {
            if ( x > 0 ) {
                add ( x ) ;
                ++ fire[ x ] ;
            }
            else {
                del ( -x ) ;
                fire.erase ( -x ) ;
            }
        }
        else {
            if ( x > 0 ) {
                ++ cnt ;
                add ( x ) ;
                ++ lightning[ x ] ;
            }
            else {
                -- cnt ;
                del ( -x ) ;
                lightning.erase ( -x ) ;
            }
        }
        ans = get_sm ( root ) ;
        if ( cnt > 0 ) {
            ans += getk ( root , cnt ) ;
        }
        if ( fire.empty ( ) == true && cnt > 0 ) {
            ans -= lightning.begin ( )->first ;
        }
        else if ( cnt > 0 ) {
            if ( fire.rbegin ( )->first < lightning.begin ( )->first ) {
                ans -= lightning.begin ( )->first ;
                ans += fire.rbegin ( )->first ;
            }
        }
        cout << ans << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}