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

int a[1024];

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, k;
  int i;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++)
    cin>>a[i];
  k--;
  while(!a[k])
    k = (k+1)%n;
  k++;
  cout<<k<<endl;
  
  return 0;
}