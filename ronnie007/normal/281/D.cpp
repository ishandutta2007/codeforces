#include <cstdio>
#include <stack>
#include <algorithm>

using namespace std;

stack < int > st;
int N;
int a[1 << 17];

void input ()
    {
    scanf ( "%d", &N ) ;

    for ( int i = 0 ; i < N ; i ++  )
        {
        scanf ( "%d" , a + i  ) ;
        }
    }



int go ( )
    {
    int res = 0 ;

    while ( !st.empty ( ) ) st.pop ( ) ;
    st.push ( a[0] ) ;

    for ( int i = 1; i < N; i ++ )
        {
        while ( st.size () )
            {
            if ( st.top ( ) > a[ i ] )
                break;
            res = max ( res, a[ i ] ^ st.top ( ) ) ;
            st.pop ( ) ;
            }
        st.push ( a[ i ] ) ;
        }
    return res ;
    }

void solve()
    {
    int res = go ( ) ;
    reverse ( a , a + N ) ;
    res = max ( go ( ) , res ) ;

    printf ( "%d\n" , res ) ;
    }

int main ( )
    {
    input ( ) ;
    solve ( ) ;
    return 0 ;
    }