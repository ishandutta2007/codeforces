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

int tos;
char s[200010], st[200010];

int main()
{
  scanf( "%s", s );
  int n = strlen( s );
  tos = 0;
  forn( i, n )
    if ( tos == 0 || st[tos-1] != s[i] ) st[tos++] = s[i];
    else tos--;
  st[tos] = 0;
  printf( "%s", st );
  return 0;
}