#include <cstdio>
using namespace std;

int n, m, t;
char s[1000], buf[1000];
int a[1000];
int id;

void alloc( int x )
{
  int cc = 0;
  for ( int i=0; i<m; i++ )
    if ( a[i] != 0 ) cc = 0;
    else
    {
      cc++;
      if ( cc == x )
      {
        id++;
        for ( int j=i-cc+1; j<=i; j++ )
          a[j] = id;
        printf( "%d\n", id );
        return;
      }
    }
  printf( "NULL\n" );
}

void defrag()
{
  int k = 0;
  for ( int i=0; i<m; i++ )
    if ( a[i] != 0 ) a[k++] = a[i];
  for ( int i=k; i<m; i++ ) a[i] = 0;
}

void erase( int x )
{
  bool ok = 1;
  for ( int i=0; i<m; i++ )
    if ( a[i] == x )
    {
      a[i] = 0;
      ok = 0;
    }

  if ( ok || x == 0 ) printf( "ILLEGAL_ERASE_ARGUMENT\n" ); 
}

int main()
{
  scanf( "%d %d", &n, &m ); gets( s );
  for ( int i=0; i<n; i++ )
  {
    gets( s );
    if ( s[0] == 'a' )
    {
      sscanf( s, "%s %d", buf, &t );
      alloc( t );
    }

    if ( s[0] == 'e' )
    {
      sscanf( s, "%s %d", buf, &t );
      erase( t );
    }         

    if ( s[0] == 'd' )
    {
      defrag();
    }
  }
}