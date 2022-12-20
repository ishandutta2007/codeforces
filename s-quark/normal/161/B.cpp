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
const int MAXN = 1004;

pair<int, pair<int, int> > a[MAXN];

int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int n, k;
  int i, j;
  int cnt = 0;
  ll sum = 0, dis = 0;
  cin>>n>>k;
  for(i = 0; i < n; i++){
    cin>>a[i].fi>>a[i].se.fi;
    a[i].se.se = i+1;
    sum += a[i].fi;
    if(a[i].se.fi == 1)
      cnt++;
  }
  sort(a, a+n, greater<pair<int, pair<int, int> > >());
  j = k;
  if(cnt >= k)
    dis += a[n-1].fi;
  for(i = 0; i < n && j > 1; i++){
    if(j > 1 && a[i].se.fi == 1){
      dis += a[i].fi;
      j--;
    }
  }
  if(dis&1)
    cout<<sum-dis/2-1<<".5"<<endl;
  else
    cout<<sum-dis/2<<".0"<<endl;
  j = k;
  for(i = 0; i < n && j > 1; i++){
    if(j > 1 && a[i].se.fi == 1){
      cout<<"1 "<<a[i].se.se<<endl;
      a[i].fi = -1;
      j--;
    }
  }
  i = n-1;
  while(j > 1){
    if(a[i].fi != -1){
      cout<<"1 "<<a[i].se.se<<endl;
      a[i].fi = -1;
      j--;
    }
    i--;
  }
  cout<<n-(k-j);
  for(i = 0; i < n; i++)
    if(a[i].fi != -1)
      cout<<" "<<a[i].se.se;
  cout<<endl;
  return 0;
}