#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl

int m,n;
unordered_set<int> S;

ll modpow(ll a,ll b,ll m){
  ll r = 1;
  while(b){
    if(b&1)r=r*a%m;
    a=a*a%m;
    b>>=1;
  }
  return r;
}

int main(){
  scanf("%d%d",&m,&n);
  int sum = 0;
  REP(i,n){
    int x;
    scanf("%d",&x);
    S.insert(x);
    sum = (sum+x)%m;
  }
  if(n==m){
    puts("1 1");
    return 0;
  }
  int ivnn1 = modpow((ll)n*(n-1)%m,m-2,m) * 2 % m;
  // sum = n*a + n(n-1)d/2
  // d = (sum-n*a)*2/n(n-1)
  // d = sum*iv - a*n*iv
  int nivnn1 = (ll)n*ivnn1%m;
  int left = (ll)sum*ivnn1%m + m;
  for(int a : S){
    int d = (left - (ll)a*nivnn1%m) % m;
    if(n>1 && S.count((a-d+m)%m))continue;
    int aa = a;
    bool flag = true;
    REP(i,n-1){
      aa = (aa+d)%m;
      if(aa==a || !S.count(aa)){
        flag=false;break;
      }
    }
    if(flag){
      printf("%d %d\n",a,d);
      return 0;
    }
  }
  puts("-1");
  return 0;
}