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

struct Event {
  int x, type, val;

  Event(int a, int b, int c) {
    x = a, type = b, val = c;
  }
};

bool operator<(const Event& i, const Event& j) {
  return i.x < j.x or (i.x == j.x and i.type < j.type);
}

vector<Event> ev;
int n, m;
int a, h, l, r, b, z;
// map<int,ld> mm;
int cnt[110];

void add( int a, int c, int b ){
  ev.push_back( Event( a, b, c ) );
}

ld binpow(ld a, int b) {
  ld res = 1;
  for ( ; b>0; b>>=1 ) {
    if ( b&1 ) res *= a;
    a *= a;
  }
  return res;
}

int main() {
  scanf( "%d %d", &n, &m );
  forn( i, n ) {
    scanf( "%d %d %d %d", &a, &h, &l, &r );
    add( a - h, 100 - l, -1 );
    add( a, 100 - l, -2 );
    add( a, 100 - r, 2 );
    add( a + h, 100 - r, 1 );
//    if ( mm.find( a ) == mm.end() ) mm[a] = 1;
//    mm[a] *= ( 100.0 - l - r ) / 100.0;
  }
  forn( i, m ) {
    scanf( "%d %d", &b, &z );
    add( b, z, 0 );
  }

  sort(ev.begin(), ev.end());

  double ans = 0;
  forn( q, ev.size() )
    if ( ev[q].type == -1 or ev[q].type == 2 ) {
      cnt[ ev[q].val ]++;
    } else
    if ( ev[q].type == 1 or ev[q].type == -2 ) {
      cnt[ ev[q].val ]--;
    } else {
      ld p = 1; //mm.find( ev[q].x ) == mm.end() ? 1 : mm[ ev[q].x ];
      if ( cnt[0] > 0 ) p = 0;
      else
        forn( q, 101 )
          p *= binpow( q / 100.0, cnt[q] );

      ans += p * ev[q].val;
    } 

  printf( "%.10f\n", ans );

  return 0;
}