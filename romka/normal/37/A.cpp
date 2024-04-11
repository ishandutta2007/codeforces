#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <ctime>
#include <cassert>
using namespace std;

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef double ld;

map<int,int> m;

int main()
{
  int n, x;
  scanf( "%d", &n );
  forn( i,n )
  {
    scanf( "%d", &x );
    m[x]++;
  }

  int b = m.size();
  int mx = -1;
  for ( map<int,int>::iterator mit = m.begin(); mit != m.end(); mit++ )
    if ( mit->second > mx ) mx = mit->second;

  printf( "%d %d\n", mx, b );
}