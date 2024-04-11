#include <cstdio>
#include <vector>
#include <memory.h>
#include <cstring>
#include <ctime>
#include <string>
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

map<string,int> mm;
int a[120];
int n;
char s[1230];
string ans[1230];

int main()
{
  mm["S"] = 0;
  mm["M"] = 1;
  mm["L"] = 2;
  mm["XL"] = 3;
  mm["XXL"] = 4;

  ans[0] = "S";
  ans[1] = "M";
  ans[2] = "L";
  ans[3] = "XL";
  ans[4] = "XXL";


  forn( i, 5 ) scanf( "%d", &a[i] );
  scanf( "%d", &n );
  forn( i, n )
  {
    scanf( "%s", s );
    int id = mm[ string(s) ];

    forn( q, 5 )
    {
      int ni = id+q;
      if ( ni < 5 && a[ni] > 0 )
      {
        a[ni]--;
        printf( "%s\n", ans[ni].c_str() );
        break;
      }

      ni = id-q;
      if ( ni >= 0 && a[ni] > 0 )
      {
        a[ni]--;
        printf( "%s\n", ans[ni].c_str() );
        break;
      }
    }
  }

  return 0;
}