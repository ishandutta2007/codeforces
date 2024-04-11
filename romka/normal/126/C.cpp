#include <cstdio>

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )

int n;
char s[2010];
bool a[2010][2010], x[2010][2010], v[2010][2010], h[2010][2010];

int main() {
  scanf( "%d", &n );
  for ( int i=1; i<=n; i++ ) {
    scanf( "%s", s );
    forn( j, n )
      a[i][j+1] = s[j] == '1';
  }

  int ans = 0;
  for ( int i=1; i<n; i++ )
    for ( int j=n; j>i; j-- ) {
      x[i][j] = v[i-1][j] ^ h[i][j+1];
      v[i][j] = v[i-1][j];
      h[i][j] = h[i][j+1];
      if (x[i][j] != a[i][j]) {
        x[i][j] ^= 1;
        h[i][j] ^= 1;
        v[i][j] ^= 1;
        ans++;
      }
    }

  for ( int i=n; i>1; i-- )
    for ( int j=1; j<i; j++ ) {
      x[i][j] = v[i+1][j] ^ h[i][j-1];
      v[i][j] = v[i+1][j];
      h[i][j] = h[i][j-1];
      if (x[i][j] != a[i][j]) {
        x[i][j] ^= 1;
        v[i][j] ^= 1;
        h[i][j] ^= 1;
        ans++;
      }
    }

  for ( int i=1; i<=n; i++ ) {
    x[i][i] = v[i-1][i] ^ h[i][i-1] ^ h[i][i+1] ^ v[i+1][i];
    ans += x[i][i] != a[i][i];
  }
      
  printf( "%d\n", ans );

  return 0;
}