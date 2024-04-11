#include <cstdio>
#include <string>
#include <vector>
#include <memory.h>
#include <cstring>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int z, y, a, b, c, d, e;
char buf[1230];

int main()
{
  int n;
  scanf( "%d", &n );
  int mx = - ( 1<<29 );
  string ans, nick;
  forn( q, n ) {
    scanf( "%s", buf );
    nick = string( buf );
    scanf( "%d %d %d %d %d %d %d", &z, &y, &a, &b, &c, &d, &e );
    int score = a+b+c+d+e+z*100-y*50;
    if ( score > mx ) {
      mx = score;
      ans = nick;
    }
  }   
  printf( "%s\n", ans.c_str() );
  return 0;
}