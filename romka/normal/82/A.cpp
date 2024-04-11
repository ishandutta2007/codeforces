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

string name[] = { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };

int z, a[10], n;

int main()
{
  scanf( "%d", &n );
  forn( i, 5 ) a[i] = 1;

  for ( int i=0; ; i++ ) {
    int z = i % 5;
    if ( n <= a[z] ) {
      printf( "%s\n", name[z].c_str() );
      return 0;
    } 
    n -= a[z];
    a[z] <<= 1;
  }

  return 0;
}