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

int n, d[1000010];
unsigned long long cnt[15];
int dc[1000010];
unsigned long long acnt[1000];

int divc( int x )
{
  int i = 2;
  int& res = dc[x];
  res = 1;
  int cnt;
  while ( i*i <= x )
    if ( x%i == 0 )
  {
    cnt = 0;
    while ( x%i == 0 )
    {
      x /= i;
      cnt++;
    }
    res *= cnt+1;
    res *= dc[x];
    x = 1;
  } else i++;

  if ( x > 1 ) res *= 2;

  return res;
}

int main()
{
  scanf( "%d", &n );

  int ffn = max( n, 100 );
  for ( int i=1; i<=ffn; i++ )
  {
    int s = 0, x = i;
    for ( ; x>0; s+=x%10, x/=10 );
    if ( s < 10 ) d[i] = s;
    else d[i] = d[s];
    if ( i <= n ) cnt[ d[i] ]++;
  }

  for ( int i=1; i<10; i++ )
    for ( int j=1; j<10; j++ )
      acnt[ d[i*j] ] += cnt[i] * cnt[j];

//  for ( int i=1; i<10; i++ ) printf( "%d\n", (int)cnt[i] );

//  for ( int i=1; i<=30; i++ )
//    printf( "%d : %d\n", i, divc(i) );

  unsigned long long ans = 0;
  for ( int i=1; i<=n; i++ )
  {
    ans += acnt[ d[i] ];
    ans -= divc( i );
  }  

  cout << ans << endl;
}