#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include <limits>
#include <list>
#include <queue>
#include <tuple>
#include <map>
#include <stack>
#include <set>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define INF (int)(1123456789)
#define LINF (long long int)(112345678901234567)
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define all(v) v.begin(), v.end()

const int N = (int)3e5;

ll mpow(ll a, ll b){
  if(b==0) return 1;
  else if(b%2==0){ll memo = mpow(a,b/2); return memo*memo%MOD;}
  else return mpow(a,b-1) * a % MOD;
}
ll lpow(ll a, ll b){
  if(b==0) return 1;
  else if(b%2==0){ll memo = lpow(a,b/2); return memo*memo;}
  else return lpow(a,b-1) * a;
}
ll gcd(ll a, ll b){
  if(b==0) return a;
  else return gcd(b, a%b);
}
vector<ll> kaijo_memo;
ll kaijo(ll n){
  if(kaijo_memo.size() > n) return kaijo_memo[n];
  if(kaijo_memo.size() == 0) kaijo_memo.push_back(1);
  while(kaijo_memo.size() <= n) kaijo_memo.push_back(kaijo_memo[kaijo_memo.size()-1] * kaijo_memo.size() % MOD);
  return kaijo_memo[n];
}
vector<ll> gyaku_kaijo_memo;
ll gyaku_kaijo(ll n){
  if(gyaku_kaijo_memo.size() > n) return gyaku_kaijo_memo[n];
  if(gyaku_kaijo_memo.size() == 0) gyaku_kaijo_memo.push_back(1);
  while(gyaku_kaijo_memo.size() <= n) gyaku_kaijo_memo.push_back(gyaku_kaijo_memo[gyaku_kaijo_memo.size()-1] * mpow(gyaku_kaijo_memo.size(), MOD-2) % MOD);
  return gyaku_kaijo_memo[n];
}

ll nCr(ll n, ll r){
  if(n == r) return 1;//0-1.
  if(n < r || r < 0) return 0;
  ll ret = 1;
  ret *= kaijo(n); ret %= MOD;
  ret *= gyaku_kaijo(r); ret %= MOD;
  ret *= gyaku_kaijo(n-r); ret %= MOD;
  return ret;
}

struct city{ll a,b,c;};
struct city2{ll a,b,c,free;};
vector<int> G[6000];

int main(void){
  ll n,m,k;
  cin>>n>>m>>k;
  vector<city> C;
  rep(i,n){
    ll a,b,c;
    cin>>a>>b>>c;
    C.push_back({a,b,c});
  }
  rep(i,m){
    int u,v;
    cin>>u>>v;
    u--;v--;
    G[u].push_back(v);
  }
  vector<ll> free;
  ll ruiseki = k;
  vector<ll> rui;
  rep(i,n){
    ll a = C[i].a;
    free.push_back(ruiseki - a);
    if(ruiseki - a < 0){
      cout<<-1<<endl;
      return 0;
    }
    ruiseki += C[i].b;
    rui.push_back(ruiseki);
  }
  ll min_free = LINF;
  bool neck[6000];
  REP(i,n){
    if(free[i] < min_free){
      neck[i] = true;
      min_free = free[i];
    }else{
      neck[i] = false;
    }
  }

  vector<city2> fake;
  REP(i,n){
    ll a = C[i].a;
    ll b = C[i].b;
    ll c = C[i].c;
      
    fake.push_back({C[i].a, C[i].b, 0, rui[i]});
    rep(j, G[i].size()){
      int next = G[i][j];
      if(C[next].c != 0){
        fake.push_back({C[next].a, C[next].b, C[next].c, rui[i]});
        C[next].c = 0;
      }
    }
    fake.push_back({C[i].a, C[i].b, C[i].c, rui[i]});
    fake.push_back({C[i].a, C[i].b, 0, free[i]});
  }

  reverse(all(fake));

  ll dp[5005], dp2[5005];
  rep(i,5005){
    dp[i] = 0;
  }

  rep(t, fake.size()){
    //ll debug = 0;
    rep(i,5005){
      dp2[i] = dp[i];
    }
    rep(i,5005){
      if(i==0) continue;
      chmax(dp2[i], dp[i-1] + fake[t].c);
    }
    rep(i,5005){
      if(i > fake[t].free){
        dp2[i] = 0;
      }
    }
    rep(i,5005){
      dp[i] = dp2[i];
      //chmax(debug, dp[i]);
    }
    //cout<<fake[t].a<<" "<<fake[t].b<<" "<<fake[t].c<<" "<<fake[t].free<<" "<<debug<<endl;
  }

  ll ans = 0;
  rep(i,5005){
    chmax(ans, dp[i]);
  }
  cout<<ans<<endl;
  return 0;
}