#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

int n;
ll l[125252];
char s[125252];

ll sum[125252];

int main(){
  scanf("%d",&n);
  REP(i,n)scanf("%lld",l+i);
  scanf("%s",s);

  REP(i,n)sum[i+1] = sum[i] + l[i];

  ll tm = 0;
  bool swimEx = false;
  deque<pll> walks, swims;
  REP(i,n){
    if(s[i]=='G'){
      // walk
      tm += 5ll * l[i];
      walks.push_back(pll(sum[i], l[i]));
    }else if(s[i]=='W'){
      // swim
      tm += 3ll * l[i];
      swims.push_back(pll(sum[i], l[i]));
      swimEx = true;
    }else{
      // need fly
      tm += 1ll * l[i];
      ll rest = l[i];
      while(rest>0 && swims.size()>0){
        ll use = min(rest, swims.back().second);
        swims.back().second -= use; rest -= use;
        if(swims.back().second == 0)swims.pop_back();
      }
      while(rest>0 && walks.size()>0){
        ll use = min(rest, walks.back().second);
        walks.back().second -= use; rest -= use;
        if(walks.back().second == 0)walks.pop_back();
      }
      if(rest > 0){
        if(swimEx){
          tm += 3ll * rest;
        }else{
          tm += 5ll * rest;
        }
      }
    }
  }
  // DEBUG(tm);
  int wit = 0, sit = 0;
  while(wit<walks.size() || sit<swims.size()){
    if(sit==swims.size() || (wit<walks.size() && walks[wit] < swims[sit])){
      // walk and fly
      tm -= 2ll * walks[wit].second;
      wit++;
    }else{
      // swim
      while(swims[sit].second>0 && wit<walks.size()){
        ll use = min(swims[sit].second, walks[wit].second);
        walks[wit].second -= use;
        swims[sit].second -= use;
        tm -= 4ll * use;
        if(walks[wit].second == 0)wit++;
        if(swims[sit].second == 0)break;
      }
      tm -= 1ll * swims[sit].second;
      sit++;
    }
  }
  printf("%lld\n",tm);
  return 0;
}