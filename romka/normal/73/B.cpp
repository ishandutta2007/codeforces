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

const int maxn = 100010;

int n, a[maxn], b[maxn], p[maxn], m, id;
map<string,int> mm;
char buf[25];
multiset<int> ss;
string name[maxn];

bool cmp( int i, int j ) {
  return a[i] > a[j];
}

int solvemin() {
  int l = 0, r = n-1;

  int oursc = a[id] + b[n-1];
  int res = 1;

  forn( i, n ) 
    if ( p[i] != id ) {
      if ( a[ p[i] ] + b[l] > oursc ) {
        r--;
        res++;
      } else l++;
    }

  return res;
}

int solvemax() {
  forn( i, n ) ss.insert( b[i] );

  int oursc = a[id] + b[0];
  int res = 1;

  forn( i, n ) if ( p[i] != id ) {
    multiset<int>::iterator it = ss.lower_bound( oursc - a[ p[i] ] );
    if ( it != ss.end() ) {
      res++;
      ss.erase( it );
    }
  } 

  return res;
}

int main()
{
  scanf( "%d", &n );
  forn( i, n ) {
    scanf( "%s %d", buf, &a[i] );
    name[i] = string(buf);
    a[i] *= 10;
    mm[ name[i] ] = i;
  }
  scanf( "%d", &m );
  forn( i, m ) scanf( "%d", &b[i] ), b[i] *= 10;
  sort( b, b+n );

  scanf( "%s", buf );
  string tname( buf );
  id = mm[tname];

  forn( i, n )
    if ( name[i] < tname ) a[i] += 2; else
    if ( name[i] > tname ) a[i] -= 2;

  forn( i, n ) p[i] = i;
  sort( p, p+n, cmp );

  printf( "%d %d\n", solvemin(), solvemax() );

  return 0;
}