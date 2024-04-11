#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, k;
  int a;
  int i;
  int ans = 0;
  cin>>n>>k;
  for(i = 0; i < n; i++)
  {
    cin>>a;
    if(a >= k)
      a -= k;
    if(a >= k)
      a -= k;
    if(a >= k)
      a -= k;
    ans += a;
  }
  cout<<ans<<endl;
  return 0;
}