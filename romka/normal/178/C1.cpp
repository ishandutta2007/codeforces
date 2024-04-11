#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
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

int h, m, n;
map<int, int> where;
char s[100];
int id, t, ans;
bool used[5010];

int main()
{
  scanf("%d %d %d", &h, &m, &n);
  ans = 0;
  forn(i, n) {
    scanf("%s %d", s, &id);
    if (s[0] == '+') {
      scanf("%d", &t);
      while (used[t]) {
        t += m;
        if (t >= h) t -= h;
        ans++;
      }
      used[t] = true;
      where[id] = t;
    } else {
      used[ where[id] ] = false;
    }
  }
  printf("%d\n", ans);
  return 0;
}