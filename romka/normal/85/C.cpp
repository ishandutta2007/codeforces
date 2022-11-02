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

int lastlca =  -1;
ld res[maxn], ans[maxn];
int submin[maxn], submax[maxn];
int gt[maxn][2];
int root, key[maxn], lcap[maxn];
int leaves[maxn], kl;
int n, m;
pii q[maxn];

void dfs( int i ) {
//  printf( "dfs %d\n", i );
  if ( gt[i][0] == -1 ) {
    submin[i] = key[i];
    submax[i] = key[i];

    if ( lastlca != -1 ) {
      lcap[i] = lastlca;
    }

    leaves[kl++] = i;

  } else {
    dfs( gt[i][0] );
    lastlca = i;
    dfs( gt[i][1] );
    submin[i] = submin[ gt[i][0] ];
    submax[i] = submax[ gt[i][1] ];
  }
}

void dfsans( int i, int h, ll sum ) {
//  printf( "dfsans %d %d %I64d\n", i, h, sum );
  if ( gt[i][0] == -1 ) {
    res[i] = (ld)1.0 * sum / h;
  } else { 
    dfsans( gt[i][0], h+1, sum + submin[ gt[i][1] ] );
    dfsans( gt[i][1], h+1, sum + submax[ gt[i][0] ] );
  } 
}

int main()
{
  scanf( "%d", &n );

  forn( i, n ) gt[i][0] = -1;
  lastlca = -1;

  int p;
  forn( i, n ) {
    scanf( "%d %d", &p, &key[i] );
    if ( p == -1 ) root = i;
    else {
      p--;
      if ( gt[p][0] == -1 ) gt[p][0] = i;
      else {
        gt[p][1] = i;
        if ( key[ gt[p][0] ] > key[ gt[p][1] ] ) {
          swap( gt[p][0], gt[p][1] );
        }
      }
    }
  }

  dfs( root );
  dfsans( root, 0, 0 );

  scanf( "%d", &m );
  forn( i, m ) scanf( "%d", &q[i].first ), q[i].second = i;

  sort( q, q+m );

//  forn( i, kl ) printf( "%d ", leaves[i] ); printf( "\n" );
//  printf( "%.10f\n", (double) res[3] );

  int curl = 0;
  forn( i, m ) {
    while ( curl < kl && key[ leaves[curl] ] < q[i].first ) curl++;

    if ( curl == 0 ) {
      ans[ q[i].second ] = res[ leaves[curl] ];
    } else
    if ( curl == kl ) 
      ans[ q[i].second ] = res[ leaves[kl-1] ];
    else {
      if ( q[i].first < key[ lcap[ leaves[curl] ] ] ) ans[ q[i].second ] = res[ leaves[curl-1] ];
      else ans[ q[i].second ] = res[ leaves[curl] ];
    }
  }

  forn( i, m )
    printf( "%.12f\n", (double)ans[i] );

  return 0;
}