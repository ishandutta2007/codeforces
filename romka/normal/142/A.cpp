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
#define foreach( it, a ) for ( __typeof((a).begin()) it = (a).begin(); it != (a).end(); it++ )
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

int n;
ll mi, ma;

void test( ll a, ll b, ll c ) {
  ll cur = (a+1)*(b+2)*(c+2); 
  if ( cur > ma ) ma = cur;
  if ( cur < mi || mi == -1 ) mi = cur;
}

void check( ll a, ll b, ll c ) {
  test( a, b, c );
  test( b, a, c );
  test( c, a, b );
}

int main() { 
  scanf( "%d", &n );
  ma = mi = -1;
  for ( int a = 1; a*a <= n; a++ )
    if ( n%a == 0 ) {
      int nn = n / a;
      for ( int b = a; b*b <= nn; b++ )
        if ( nn % b == 0 ) {
          int c = nn / b;
          check( a, b, c );
        }
    }
  cout << mi-n << " " << ma-n << endl;
  return 0;
}