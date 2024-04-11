#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
//#include <map>
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
  int t, i0;
  cin>>t;
  FOR(i0, 0, t)
  {
    int n;
    cin>>n;
    cout<<((n&1)^1)<<endl;
  }
  return 0;
}