#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
enum Color{ Cl_White = 0, Cl_Green = 1, Cl_Black = 2 } ;
  
struct vertex
{
    int head        ;
    int color       ;
    int deep  [ 2 ] ;
    int parent[ 2 ] ;

};

struct edge
{
    int nxt ;
    int dst ;
};

struct vertex * v;
struct edge   * e;
int cycled ;

int dfs(int cur, int odd)
{
    v[cur].color = Cl_Green;
    v[cur].deep[ odd ] = 1;
    
    for(int h = v[ cur ].head;  h != 0; h = e[h].nxt )
    {
        int y = e[ h ].dst ;
        if (v[y].color == Cl_White ) // a new not visited vertex
        {
            v[y].parent[ odd ^ 1 ] = cur;
            dfs(y, odd ^ 1 ) ;
        } 
        else 
        {
            if (v[y].color == Cl_Green )
                 cycled = 1;
            // we have a cycle.
            
            if ( ! v[y].deep[ odd ^ 1 ] ) 
            {
                v[y].parent[ odd ^ 1 ] = cur;
                dfs(y, odd ^ 1 );
            }
        }
    }
    //re-color this vertex as black
    v[cur].color = Cl_Black;
    return 0;
}

static int solve()
{
    
    int N, M, p = 0 ;
    scanf("%d%d", &N, &M ) ;
    v = (struct vertex * )malloc(( N + 1 ) * sizeof(struct vertex ) ) ;
    if ( ! v ) 
        exit( -1 ) ;
    e = (struct edge *  ) malloc((M+1) * sizeof(struct edge ) ) ;
    if ( ! e )
        exit(-1) ;
    
    memset(v, 0, (N+1) * sizeof(struct vertex) ) ;
    cycled = 0;
    
    for(int i = 1; i <= N; ++i)
    {
        int ci;
        scanf("%d", &ci);
        
        for(int j = 0; j < ci; ++j)
        {
            int x;
            scanf("%d", &x);
            
            ++p;
            
            e[ p ].nxt = v[ i ].head ;
            e[ p ].dst = x ;
            
            v[ i ].head = p ;
            
        }
    }
    
    int src = 0 ;
    scanf("%d", &src);
    
    dfs( src, 0 ) ;
    
    //1 --> 2 --> 4 -- > 5
    int target = 0;
    for(int i = 1; i <= N; ++i)
    {
        if (v[ i ].head == 0 ) // a leaf
        {
            if ( v[ i ].deep[ 1 ] ) // has odd path.
            {
                target = i ;
                break;
            }
        }
    }
    
    
    if (target > 0 )
    {
        printf("Win\n");
        //there may be no more N*2 items.
        int * ans = ( int * ) malloc( ( N + 1 ) * 2 * sizeof( int ) ) ;
        if ( ! ans ) 
            exit( -1 ) ;
        
        int pos = 0 ;
        int odd = 1 ;
        while(target > 0)
        {
            ans[ pos++ ] = target ;
            target = v[ target ].parent [ odd ] ;
            
            odd ^= 1 ;
            
            
        }
        
        for(int i = pos - 1; i >= 0; --i)
            printf("%d ", ans[i]);
        
        free( ans ) ;
    }
    else if (cycled ) 
    {
        printf("Draw\n");
    }
    else
    {
        printf("Lose\n");
    }
    
    free( v );
    free( e );
         
    return 0;
}

int main() 
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif     
    
    solve();
    return 0;
}