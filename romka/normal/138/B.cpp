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

int cnt[11], cnt2[11], bf;
char s[100010], ans1[100010], ans2[100010];
int k1, k2;

int get9() {
  int res = 0;
  forn( q, 10 )
    res += min( cnt[q], cnt2[9-q] );
  return res;
}

int get() {
  int mx = 0;
  bf = -1;
  forn( i, 10 ) cnt2[i] = cnt[i];
  for ( int f = 1; f <= 9; f++ ) {
    if ( cnt[f] > 0 and cnt2[10-f] > 0 ) {
      cnt[f]--;
      cnt2[10-f]--;
      int cur = get9();
      if ( cur + 1 > mx ) {
        mx = cur + 1;
        bf = f;
      }
      cnt2[10-f]++;
      cnt[f]++;
    }
  }          
  return mx;
}

void printCnt() {
  forn( i, 10 ) printf( "%d ", cnt[i] ); printf( "\n" );
}

void print( int cq, int lf ) {
  forn( q, cq ) ans1[k1++] = '0', ans2[k2++] = '0';
  cnt[0] -= cq;
  forn( i, 10 ) cnt2[i] = cnt[i];

  if ( lf != -1 ) {
    ans1[k1++] = '0' + lf, ans2[k2++] = '0' + 10 - lf;
    cnt[lf]--, cnt2[10-lf]--;
  }

 // printCnt();
  forn( q, 10 ) {
    int cc = min( cnt[q], cnt2[9-q] );
    cnt[q] -= cc, cnt2[9-q] -= cc;
    forn( z, cc ) ans1[k1++] = '0' + q, ans2[k2++] = '9' - q;
  }

  forn( q, 10 )
    forn( z, cnt[q] )
      ans1[k1++] = '0' + q;
      
  forn( q, 10 )
    forn( z, cnt2[q] )
      ans2[k2++] = '0' + q;

  reverse( ans1, ans1+k1 );
  reverse( ans2, ans2+k2 );
  ans1[k1] = ans2[k2] = 0;
  printf( "%s\n%s\n", ans1, ans2 );
}

int main() { 
  scanf( "%s", s );
  int n = strlen( s );
  forn( i, n )
    cnt[ s[i] - '0' ]++;

  int ans = -1, cq = -1, lf = -1;
  int t = cnt[0] + 1;
  forn( q, t ) {
    int cur = get();
//    printf( "q = %d, cur = %d, ans = %d\n", q, cur, ans );
    if ( cur + q > ans ) {
      ans = cur + q;
      cq = q;
      lf = bf;
    }
    cnt[0]--;
  }
  cnt[0] = t - 1;

  print( cq, lf );

  return 0;
}