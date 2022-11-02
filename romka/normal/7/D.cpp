#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <memory.h>
using namespace std;

typedef long long ll;
const int maxn = 5000010;
const int p = 271;

char s[maxn];
int n;
ll h[maxn], ht[maxn], pp[maxn];
int f[maxn];

int main()
{
  gets( s );
  n = strlen( s );

  if ( n == 0 )
  {
    printf( "0\n" );
    return 0;
  }

  pp[0] = 1;
  for ( int i=1; i<=n; i++ ) pp[i] = pp[i-1]*p;


  h[0] = s[0];
  for ( int i=1; i<n; i++ ) h[i] = h[i-1]*p + s[i];

  ht[n-1] = s[n-1];
  for ( int i=n-2; i>=0; i-- ) ht[i] = ht[i+1]*p + s[i];

  f[0] = 1;
  ll ans = 1; 

  for ( int i=1; i<n; i++ )
  {
    int len = (i+1)/2;
    ll h1 = h[len-1];
    ll h2 = ht[i-len+1] - ht[i+1]*pp[len];

    if ( h1 != h2 ) f[i] = 0;
    else ans += f[i] = f[len-1] + 1;
  }

  cout << ans << endl;
}