#include <cstdio>
#include <memory.h>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

string a[10010];
char s[10010];
int n, k;

bool isvowel( char c ) {
  return c == 'a' or c == 'o' or c == 'e' or c == 'u' or c == 'i';
}

int main() {
  scanf("%d %d", &n, &k );
  forn( i, 4*n ) {
    scanf( "%s", s );
    int len = strlen( s );
    int cnt = 0;
    for ( int j=len-1; j>=0; j-- ) {
      if ( isvowel( s[j] ) ) cnt++;
      if ( cnt == k ) {
        a[i] = string( s + j );
        break;
      }
    }

    if ( a[i].size() == 0 ) a[i] += '0' + (i % 4);
  }

  bool aabb = true, abba = true, abab = true;

  for ( int i=0; i<4*n; i += 4 ) {
    aabb &= a[i] == a[i+1] and a[i+2] == a[i+3];
    abba &= a[i] == a[i+3] and a[i+1] == a[i+2];
    abab &= a[i] == a[i+2] and a[i+1] == a[i+3];
  }

  if ( aabb and abba and abab ) printf( "aaaa\n" );
  else if ( aabb ) printf( "aabb\n" );
  else if ( abba ) printf( "abba\n" );
  else if ( abab ) printf( "abab\n" );
       else printf( "NO\n" );    

  return 0;
}