#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <utility>
#include <set>
#include <string.h>
#include <string>
#include <memory.h>
#include <ctime>
#include <cmath>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back

vector< vector<int> > f[260][260];
vector<int> p[260][260], pl[260][260];
int n, k[15], next[12][1010][260];
int a[15][1010];

int main()
{
  scanf( "%d", &n );
  forn( i,n )
  {
    scanf( "%d", &k[i] );
    forn( j, k[i] ) scanf( "%d", &a[i][j+1] );

    forn( q, 260 ) next[i][k[i]][q] = k[i]+1;

    for ( int j=k[i]-1; j>=0; j-- )
    {
      forn( q, 260 ) next[i][j][q] = next[i][j+1][q];
      next[i][j][ a[i][j+1] ] = j+1;
    }
  }

  f[0][0].pb( vector<int>( 10 ) );
  vector<int> z;

  int ansi = 0, ansj = 0, ansl = 0;

  forn( i,260 )
    forn( j,260 )
      forn( l, f[i][j].size() )
      {
        if ( i > ansi )
        {
          ansi = i;
          ansj = j;
          ansl = l;
        }

        for ( int nn=j; nn<260; nn++ )
        {
          z = f[i][j][l];
          bool ok = 1;
          forn( w,n )
          {
            z[w] = next[w][ z[w] ][nn];
            if ( z[w] == k[w]+1 )
            {
              ok = 0;
              break;
            }
          }
          if ( ok )
          {
            ok = 1;
            forn( ll, f[i+1][nn+1].size() )
            {
              bool ok2 = 0;
              forn( w,n )
                if ( z[w] < f[i+1][nn+1][ll][w] )
                {
                  ok2 = 1;
                  break;
                }
              if ( !ok2 )
              {
                ok = 0;
                break;
              }
            }

            if ( ok && f[i+1][nn+1].size() < 10 ) 
            {
//              printf( "add to %d %d\n", i+1, nn+1 );
              f[i+1][nn+1].pb( z ); 
              p[i+1][nn+1].pb( j );
              pl[i+1][nn+1].pb( l );
            }
          }
        } 
      } 
     
  int tmp = 0;
  printf( "%d\n", ansi );
  vector<int> ans;
  while ( ansi > 0 )
  {
    ans.pb( ansj-1 );
    tmp = p[ansi][ansj][ansl];
    ansl = pl[ansi][ansj][ansl];
    ansj = tmp;
    ansi--;
  }

  for ( int i=ans.size()-1; i>=0; i-- )
  {
    printf( "%d", ans[i] );
    printf( " " );
  }
}