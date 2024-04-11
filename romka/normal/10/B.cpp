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

const int inf = 1000000000;

int a[111][110];
int n, k, m;

int aa( int x )
{
  return x < 0 ? -x : x;
}

int main()
{
  scanf( "%d %d", &n, &k );
  int c = k >> 1;
  forn( i,n )
  {
    scanf( "%d", &m );

    int ans = inf;
    int ansi = -1, ansj = -1;
    forn( i,k )
      forn( j,k-m+1 )
      {
        int cur = 0;
        bool ok = 1;
        forn( q,m )
          if ( a[i][j+q] == 1 )
          {
            ok = 0;
            break;
          }
          else
            cur += aa( i-c ) + aa( j+q-c );

        if ( ok && cur < ans )
        {
          ans = cur;
          ansi = i;
          ansj = j;
        }
      } 

    if ( ans == inf ) printf( "-1\n" );
    else 
    {
      printf( "%d %d %d\n", ansi+1, ansj+1, ansj+m );
      forn( q,m )
        a[ansi][ansj+q] = 1;
    }
  }
}