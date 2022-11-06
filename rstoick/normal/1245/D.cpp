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

ll n;
struct edge{
  ll u,v,c;
};

int par[3000];
int find(int a){
  if(par[a] == a){
    return a;
  }else{
    return par[a] = find(par[a]);
  }
}

void unite(int a, int b){
  int pa = find(a);
  int pb = find(b);
  par[pa] = pb;
}

int main(void){
  cin>>n;
  vector<ll> X,Y,C,K;
  rep(i,n){
    ll x,y;
    cin>>x>>y;
    X.push_back(x);
    Y.push_back(y);
  }
  rep(i,n+1){
    par[i]=i;
  }
  rep(i,n){
    ll c;
    cin>>c;
    C.push_back(c);
  }
  rep(i,n){
    ll k;
    cin>>k;
    K.push_back(k);
  }

  vector<edge> E;
  rep(i,n){
    rep(j,n){
      if(i>=j) continue;
      E.push_back({i,j,(K[i]+K[j])*(abs(X[i]-X[j])+abs(Y[i]-Y[j]))});
    }
    E.push_back({i,n,C[i]});
  }
  sort(all(E),[](const edge &a, const edge &b){
    return a.c < b.c;
  });
  vector<pair<int,int>> tunagi;
  vector<int> oya;
  ll ans = 0;
  rep(i,E.size()){
    int a = E[i].u;
    int b = E[i].v;
    if(find(a) == find(b)){
      continue;
    }
    if(b == n){
      oya.push_back(a);
    }else{
      tunagi.push_back({a,b});
    }
    ans += E[i].c;
    unite(a,b);
  }
  cout<<ans<<endl;
  cout<<oya.size()<<endl;
  rep(i,oya.size()){
    cout<<oya[i]+1;
    if(i != oya.size()-1) cout<<" ";
    else cout<<endl;
  }
  cout<<tunagi.size()<<endl;
  rep(i,tunagi.size()){
    cout<<tunagi[i].first+1<<" "<<tunagi[i].second+1<<endl;
  }
  return 0;
}