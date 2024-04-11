#include <cstdio>
#include <iostream>
#include <utility>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;

int n, m, t;
char s[256];
int a[300][300], sh[300][330], sv[300][300], ss[300][300], sb[300][300];

bool fullh( int i1, int j1, int i2, int j2 )
{
  return sh[i1][j2] - sh[i1][j1-1] == j2-j1+1;
}

bool freeh( int i1, int j1, int i2, int j2 )
{
  return sh[i1][j2] - sh[i1][j1-1] == 0;
}

bool fullv( int i1, int j1, int i2, int j2 )
{
  return sv[i2][j2] - sv[i1-1][j2] == i2-i1+1;
}

bool freev( int i1, int j1, int i2, int j2 )
{
  return sv[i2][j2] - sv[i1-1][j2] == 0;
}

bool fulls( int i1, int j1, int i2, int j2 )
{
  return ss[i2][j2] - ss[i1-1][j1+1] == i2-i1+1;
}

bool frees( int i1, int j1, int i2, int j2 )
{
  return ss[i2][j2] - ss[i1-1][j1+1] == 0;
}

bool fullb( int i1, int j1, int i2, int j2 )
{
  return sb[i2][j2] - sb[i1-1][j1-1] == j2-j1+1;
}

bool freeb( int i1, int j1, int i2, int j2 )
{
  return sb[i2][j2] - sb[i1-1][j1-1] == 0;
}

int main()
{
  scanf( "%d", &t );
  while ( t-- )
  {
    scanf( "%d %d", &n, &m );
    gets( s );
    forn( i,n )
    {
      gets( s );
      forn( j,m )
        a[i+3][j+3] = s[j] == '1';
      for ( int j=m; j<=m+5; j++ ) a[i+3][j+3] = 0;
    }
    for ( int i=n; i<=n+5; i++ )
      forn( j, m+6 ) a[i+3][j+3] = 0;

  for ( int i=1; i<=n+5; i++ )
    for ( int j=1; j<=m+5; j++ )
    {
      sh[i][j] = sh[i][j-1] + a[i][j];
      sv[i][j] = sv[i-1][j] + a[i][j];
      sb[i][j] = sb[i-1][j-1] + a[i][j];
      ss[i][j] = ss[i-1][j+1] + a[i][j];
    }

  int ans = 0;

  for ( int i=3; i<=n+2; i++ )
    for ( int j=3; j<=m+2; j++ )
    {
      if ( fullh( i, j, i, j+1 ) && fullh( i+1, j, i+1, j+1 ) &&
           freeh( i-1, j-1, i-1, j+2 ) && freeh( i+2, j-1, i+2, j+2 ) &&
           freev( i-1, j-1, i+2, j-1 ) && freev( i-1, j+2, i+2, j+2 ) ) ans++;

       for ( int k=1; i+k-1 <= n+2 && j+k-1 <= m+2; k++ )
       {
         if ( k > 2 )
         if ( fullh( i, j, i, j+k-1 ) && fullh( i+k-1, j, i+k-1, j+k-1 ) &&
              fullv( i, j, i+k-1, j ) && fullv( i, j+k-1, i+k-1, j+k-1 ) &&
              freeh( i-1, j-1, i-1, j+k ) && freeh( i+k, j-1, i+k, j+k ) &&
              freev( i-1, j-1, i+k, j-1 ) && freev( i-1, j+k, i+k, j+k ) &&
              freeh( i+1, j+1, i+1, j+k-2 ) && freeh( i+k-2, j+1, i+k-2, j+k-2 ) &&
              freev( i+1, j+1, i+k-2, j+1 ) && freev( i+1, j+k-2, i+k-2, j+k-2 ) ) ans++;

         if ( i-k >= 3 && j-k >= 3 )
         {
           if ( fullb( i-k, j, i, j+k ) && fullb( i, j-k, i+k, j ) &&
                fulls( i-k, j, i, j-k ) && fulls( i, j+k, i+k, j ) &&
                freeb( i-k-1, j, i, j+k+1 ) && freeb( i-k-1, j+1, i-1, j+k+1 ) && 
                freeb( i, j-k-1, i+k+1, j ) && freeb( i+1, j-k-1, i+k+1, j-1 ) &&
                freeb( i-k+1, j, i, j+k-1 ) && freeb( i-k+2, j, i, j+k-2 ) && 
                freeb( i, j-k+1, i+k-1, j ) && freeb( i, j-k+2, i+k-2, j ) &&
                frees( i-k-1, j, i, j-k-1 ) && frees( i-k-1, j-1, i-1, j-k-1 ) &&
                frees( i, j+k+1, i+k+1, j ) && frees( i+1, j+k+1, i+k+1, j+1 ) && 
                frees( i-k+1, j, i, j-k+1 ) && frees( i-k+2, j, i, j-k+2 ) &&
                frees( i, j+k-1, i+k-1, j ) && frees( i, j+k-2, i+k-2, j ) ) ans++;

         }
       }
    }

  printf( "%d\n", ans );

  }
}