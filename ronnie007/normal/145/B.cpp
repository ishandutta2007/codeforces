#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <map>
#include <queue>
#include <set>
#include <string>
using namespace std ;
typedef pair<int,int> par ;
#define f first
#define s second

int main()
    {
    int a, b, x, y ;
    int p, q, i ;

    cin >> a >> b >> x >> y ;

    if( abs(x-y)>1 )
        {
        printf("-1\n" ) ;
        return 0 ;
        }

    if( x==y ) {
        if( a>=x && b>=x && max(a,b)>=x+1  )
            {
            if( a-1>=x )
                {
                p = a-x-1 ;
                q = b-x ;
                printf("4" ) ;
                for( ; p; p-- )
                    printf("4" ) ;
                i = 1 ;
                }
            else
                {
                p = a-y ;
                q = b-y-1 ;
                i = 0 ;
                printf("7") ;
                }
            }
        else
            {
            printf("-1\n" ) ;
            return 0 ;
            }
        }
    else
        {
        if( a>=max(x,y) && b>=max(x,y)   )
            {
            if( x<y )
                {
                p = a-y ;
                q = b-y ;
                i = 0 ;
                printf("7") ;
                }
            else
                {
                p = a-x ;
                q = b-x ;
                printf("4" ) ;
                for( ; p; p-- )
                    printf("4" ) ;
                i = 1 ;
                }
            }
        else
            {
            printf("-1\n" ) ;
            return 0 ;
            }
        }

    for( x=x+y; x; x--, i=(i+1)%2 ) {
        if( i==0 )
            {
            printf("4" ) ;
            for( ; p; p-- )
                printf("4" ) ;
            }
        else
            {
            printf("7" ) ;
            for( ; q && x-i<=1; q-- )
                printf("7" ) ;
            }
        }
    printf("\n" ) ;

    return 0 ;
    }