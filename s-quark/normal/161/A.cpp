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
const int MAXN = 100004;

int a[MAXN], b[MAXN];
pair<int, int> ans[MAXN];
int k;

int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int n, m, x, y;
  int i, j;
  cin>>n>>m>>x>>y;
  k = 0;
  for(i = 0; i < n; i++)
    cin>>a[i];
  for(j = 0; j < m; j++)
    cin>>b[j];
  sort(a, a+n);
  sort(b, b+m);
  i = 0;
  j = 0;
  while(i < n && j < m){
    if(b[j] >= a[i]-x && b[j] <= a[i]+y){
      ans[k++] = mp(i, j);
      i++, j++;
    }
    else if(b[j] > a[i])
      i++;
    else j++;
  }
  cout<<k<<endl;
  for(i = 0; i < k; i++)
    cout<<ans[i].fi+1<<" "<<ans[i].se+1<<endl;
  return 0;
}