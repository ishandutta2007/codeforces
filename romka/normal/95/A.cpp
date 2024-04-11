#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <ctime>
#include <memory.h>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define foreach( it,a ) for ( __typeof((a).begin()) it = (a).begin(); it != (a).end(); it++ )
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;

char s[110], S[110];
char T[110][110], t[110][110];
int n;
char buf[123];
char letter;
bool u[110];

int main() {
  scanf( "%d", &n );
  forn( i, n ) scanf( "%s", t[i] );
  scanf( "%s", s );
  int len = strlen( s );
  scanf( "%s", buf );
  letter = buf[0];
  if ( letter >= 'A' && letter <= 'Z' ) letter = letter - 'A' + 'a';

  forn( i, len ) S[i] = s[i] >= 'a' && s[i] <= 'z' ? s[i] - 'a' + 'A' : s[i];
  forn( j, n ) {
    int lj = strlen( t[j] );
    forn( q, lj )
      T[j][q] = t[j][q] >= 'a' && t[j][q] <= 'z' ? t[j][q] - 'a' + 'A' : t[j][q];
  } 

  forn( j, n ) {
    int lj = strlen( t[j] );
    forn( i, len-lj+1 ) {
      bool flag = true;
      forn( q, lj )
        if ( S[i+q] != T[j][q] ) {
          flag = false;
          break;
        }
      if ( flag ) 
        forn( q, lj )
          u[i+q] = 1;
    }
  }

  char mi = letter == 'a' ? 'b' : 'a';

  forn( i, len )
    if ( u[i] ) {
      if ( s[i] >= 'a' && s[i] <= 'z' ) 
        s[i] = s[i] == letter ? mi : letter;
      else s[i] = s[i] == letter - 'a' + 'A' ? mi - 'a' + 'A' : letter - 'a' + 'A';
    }

  printf( "%s\n", s );


  return 0;
}