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

ll ans;
ll a, b, c;
ll fac[3000004];
ll fac1[3000004];
ll p[20];
int num[20];
int cnt, cnt1;
ll V;
int n;

int get(ll a){
  int i, j;
  int s = (int)sqrt(a);
  int best = 1;
  cnt1 = 1;
  fac1[0] = 1;
  for(i = 0; i < n; i++){
    int t = cnt1;
    ll pow1 = p[i];
    while(a%pow1 == 0){
      for(j = 0; j < t; j++){
        fac1[cnt1] = fac1[j]*pow1;
        if(fac1[cnt1] <= s){
          best = max(best, (int)fac1[cnt1]);
          cnt1++;
        }
      }
      pow1 *= p[i];
    }
  }
  return best;
}

void sort(){
  sort(fac, fac+cnt);
}

int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int T, i0;
  cin>>T;
  for(i0 = 0; i0 < T; i0++){
    int i, j;
    cin>>n;
    for(i = 0; i < n; i++)
      cin>>p[i]>>num[i];
    cnt = 1;
    fac[0] = 1;
    V = 1;
    for(i = 0; i < n; i++){
      int t = cnt;
      ll pow1 = 1;
      for(int k = 1; k <= num[i]; k++){
        pow1 *= p[i];
        for(j = 0; j < t; j++)
          fac[cnt++] = fac[j]*pow1;
      }
      V *= pow1;
    }
    ans = 1LL<<62;
    for(i = cnt-1; i >= 0; i--){
      if(V/fac[i]/fac[i] < fac[i])
        continue;
      int s = (int)sqrt(V/fac[i]);
      if(V/fac[i] + fac[i]*s*2 >= ans)
        continue;
      s = get(V/fac[i]);
      if(V/fac[i] + fac[i]*(V/fac[i]/s+s) < ans){
        ans = V/fac[i] + fac[i]*(V/fac[i]/s+s);
        a = fac[i];
        b = s;
        c = V/fac[i]/s;
      }
    }
    cout<<ans*2<<" "<<a<<" "<<b<<" "<<c<<endl;
  }
  return 0;
}