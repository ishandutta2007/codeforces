#include<bits/stdc++.h>
using namespace std ;


#define MAXN 300007

int n , q ;
int a[ MAXN ] ;

struct node {
    long long sum ;
    int len ;
    node *pl , *pr ;
    int swap_lazy , rev_lazy ;
    node ( int _len , int _val ) {
        this->len = _len ;
        this->sum = _val ;
        this->pl = this->pr = NULL ;
        this->swap_lazy = this->rev_lazy = 0 ;
    }
};

void unite ( node *aux ) {
    aux->sum = 0 ;
    if ( aux->pl != NULL ) {
        aux->sum += aux->pl->sum ;
    }
    if ( aux->pr != NULL ) {
        aux->sum += aux->pr->sum ;
    }
}

void push_lazy ( node *aux ) {
    int hh1 = aux->swap_lazy & 1 ;
    int hh2 = aux->rev_lazy & 1 ;
    if ( hh1 > 0 ) {
        swap ( aux->pl , aux->pr ) ;
    }
    if ( hh2 > 0 ) {
        swap ( aux->pl , aux->pr ) ;
        if ( aux->pl != NULL ) {
            aux->pl->rev_lazy ^= 1 ; 
        }
        if ( aux->pr != NULL ) {
            aux->pr->rev_lazy ^= 1 ;
        }
    }
    if ( aux->pl != NULL ) {
        aux->pl->swap_lazy ^= ( aux->swap_lazy >> 1 ) ;
        aux->pl->rev_lazy ^= ( aux->rev_lazy >> 1 ) ;
    }
    if ( aux->pr != NULL ) {
        aux->pr->swap_lazy ^= ( aux->swap_lazy >> 1 ) ;
        aux->pr->rev_lazy ^= ( aux->rev_lazy >> 1 ) ;
    }
    aux->swap_lazy = aux->rev_lazy = 0 ;
}

void init_tree ( node *(&w) , int l , int r ) {
    if ( l == r ) {
        w = new node ( r - l + 1 , a[ l ] ) ;
        return ;
    }
    w = new node ( r - l + 1 , 0 ) ;
    int mid = ( l + r ) / 2 ;
    init_tree ( w->pl , l , mid ) ;
    init_tree ( w->pr , mid + 1 , r ) ;
    unite ( w ) ;
}

void update_pos ( node *w , int pos , int val , int coef ) {
    push_lazy ( w ) ;
    if ( coef + w->len < pos || pos < coef + 1 ) {
        return ;
    }
    if ( w->len == 1 ) {
        w->sum = val ;
        return ;
    }
    update_pos ( w->pl , pos , val , coef ) ;
    update_pos ( w->pr , pos , val , coef + w->pl->len ) ;
    unite ( w ) ;
}

long long query ( node *w , int st , int en , int coef ) {
    push_lazy ( w ) ;
    if ( coef + w->len < st || en < coef + 1 ) { return 0 ; }
    if ( st <= coef + 1  && coef + w->len <= en ) { return w->sum ; }
    return query ( w->pl , st , en , coef ) + query ( w->pr , st , en , coef + w->pl->len ) ;
}

node *root ;

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    for ( int i = 1 ; i <= ( 1 << n ) ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    init_tree ( root , 1 , (1<<n) ) ;
}

void solve ( ) {
    int type , x , y ;
    while ( q -- ) {
        scanf ( "%d" , &type ) ;
        if ( type == 1 ) {
            scanf ( "%d%d" , &x , &y ) ;
            update_pos ( root , x , y , 0 ) ;
        }
        else if ( type == 2 ) {
            scanf ( "%d" , &x ) ;
            root->rev_lazy ^= ( 1 << ( n - x ) ) ;
        }
        else if ( type == 3 ) {
            scanf ( "%d" , &x ) ;
            root->swap_lazy ^= ( 1 << ( n - x - 1 ) ) ;
        }
        else {
            scanf ( "%d%d" , &x , &y ) ;
            printf ( "%lld\n" , query ( root , x , y , 0 ) ) ;
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