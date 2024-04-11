#include <cstdio>
#include <ctime>
#include <utility>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;

int it;
int u[9][7][1<<8][20][2];
ll f[9][7][1<<8][20][2];
int d[20], kd;

inline short setbit( short mask, int j )
{
  if ( j < 2 ) return mask;
  mask |= 1 << (j-2);
  if ( j == 4 ) mask = ~( (~mask)|(1<<0) );
  if ( j == 6 ) mask = ~( (~mask)|(1<<0)|(1<<1) );
  if ( j == 8 ) mask = ~( (~mask)|(1<<0)|(1<<2) );
  if ( j == 9 ) mask = ~( (~mask)|(1<<1) );
  return mask;
}

int last3;

ll getf( int m9, int m7, short mask, char i, bool eq )
{
  if ( u[m9][m7][mask][i][eq] == it || ( eq == 0 && u[m9][m7][mask][i][eq] != 0 ) ) return f[m9][m7][mask][i][eq];
  ll& res = f[m9][m7][mask][i][eq];
  u[m9][m7][mask][i][eq] = it;

//  printf( "getf %d %d mask=%d i=%d, %d\n", m9, m7, mask, i, eq );

  res = 0;
  if ( i == 2 )
  {
    m9 *= 1000, m7 *= 1000;
    int nmask, n9, n7;
    bool ok;
    int lim = 1000;
    if ( eq ) lim = last3+1;
    forn( j, lim )
    {
      nmask = setbit( mask,j%10 );
      nmask = setbit( nmask,j/10%10 );
      nmask = setbit( nmask,j/100 );
      n9 = ( m9+j ) % 9;
      n7 = ( m7+j ) % 7;

//      if ( j == 116 ) printf( "n9=%d (%d), n7=%d, mask = %d\n", n9, m9, n7, nmask );

      ok = true;
      if ( nmask & (1<<0) ) ok &= (j&1) == 0; // 2
      if ( nmask & (1<<1) ) ok &= n9%3 == 0; // 3
      if ( nmask & (1<<2) ) ok &= (j&3) == 0; // 4
      if ( nmask & (1<<3) ) ok &= (j%5) == 0; // 5
      if ( nmask & (1<<4) ) ok &= (j&1) == 0 && n9%3 == 0; // 6
      if ( nmask & (1<<5) ) ok &= n7 == 0; // 7
      if ( nmask & (1<<6) ) ok &= (j&7) == 0; // 8
      if ( nmask & (1<<7) ) ok &= n9 == 0; // 9
           
      res += ok;
    }

//    printf( "-> %I64d\n", res );
  }
  else
  {
    int lim = 10;
    if ( eq ) lim = d[i] + 1;
    forn( j, lim )
      res += getf( m9+j >= 9 ? m9+j-9 : m9+j, (m7*10+j)%7, setbit(mask,j), i-1, eq && j == lim-1 );
  }

  return res;
}

bool ok( ll n )
{
  int k = 0;
  for ( ll i=n; i>0; i/=10 )
    d[k++] = i % 10;

  forn( q, k )
    if ( d[q] != 0 && n % d[q] != 0 ) return false;

  return true;
}

ll solve( ll R )
{
  last3 = R % 1000;
  if ( R < 100 )
  {
    int res = 0;
    for ( int i=0; i<=R; i++ ) res += ok( i );
    return res;
  }

  it++;
  kd = 0;
  for ( ; R>0; R/=10 ) d[kd++] = R%10;

  return getf( 0, 0, 0, kd-1, 1 );
}

int naive( ll L, ll R )
{
  int res = 0;
  for ( ll i=L; i<=R; i++ )
    res += ok( i );
  return res;
}

int main()
{
  int tc;
  scanf( "%d", &tc );
  while ( tc-- )
  {
    ll L, R;
    scanf( "%I64d %I64d", &L, &R );
    printf( "%I64d\n", solve( R ) - solve( L-1 ) );
//    printf( "naive %d\n", naive( L, R ) );
  }
  fprintf( stderr, "time %.3f sec\n", (double)clock() / CLOCKS_PER_SEC );
  return 0;
}