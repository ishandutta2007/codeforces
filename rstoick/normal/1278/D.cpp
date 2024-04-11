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
#define fast_io ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
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

int par[(int)(5*1e5+3)];

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

struct node{ll id,l,r;};

int main(void){
  fast_io

  ll n;cin>>n;
  vector<node> kukan;
  rep(i,n){
    ll l,r;cin>>l>>r;
    kukan.push_back({i,l,r});
  }
  sort(all(kukan),[](const node &a, const node &b){
    return a.l < b.l;
  });
  rep(i,n){
    par[i] = i;
  }
  auto cmp = [](const node &a, const node &b){
    return a.r > b.r;
  };
  priority_queue<node, vector<node>, decltype(cmp)> q(cmp);
  rep(i,n){
    node next = kukan[i];
    ll l = next.l;
    ll r = next.r;
    ll id = next.id;
    //cout<<id<<" "<<l<<" "<<r<<endl;
    while(q.size() > 0 && q.top().r < l){
      q.pop();
    }
    vector<node> memo;
    while(q.size() > 0){
      node hikaku = q.top();
      if(hikaku.r < r){
        if(find(id) == find(hikaku.id)){
          cout<<"NO"<<endl;
          return 0;
        }else{
          unite(id, hikaku.id);
        }
        memo.push_back(hikaku);
        q.pop();
      }else{
        break;
      }
    }
    q.push(next);
    rep(j,memo.size()){
      q.push(memo[j]);
    }
  }
  int root = find(0);
  rep(i,n){
    //cout<<i<<" "<<find(i)<<endl;
    if(find(i) != root){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
  return 0;
}