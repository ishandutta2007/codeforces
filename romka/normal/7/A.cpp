#include <cstdio>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )

char s[10][10];
int ans;
int c[2][10];

void check( int cnt )
{
  bool ok = 1;
  forn( i,8 )
    forn( j,8 )
      if ( s[i][j] == 'B' && c[0][i] != 1 && c[1][j] != 1 ||
           s[i][j] == 'W' && ( c[0][i] == 1 || c[1][j] == 1 ) )
      {
        ok = 0;
        break;
      }

  if ( ok && cnt < ans ) ans = cnt;
}

void rec( int i, int j, int cnt )
{
  if ( j == 8 )
  {
    if ( i == 0 ) rec( 1, 0, cnt );
    else check( cnt );
    return;
  }

  c[i][j] = 1;
  rec( i, j+1, cnt+1 );
  c[i][j] = 0;
  rec( i, j+1, cnt );
}

int main()
{
  ans = 100;
  forn( i,8 )
    gets( s[i] );

  rec( 0, 0, 0 );

  printf( "%d\n", ans );
}