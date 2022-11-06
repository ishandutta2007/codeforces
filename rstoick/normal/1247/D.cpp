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
#define LINF (long long int)(1e18+1)
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
  else if(b%2==0){
    ll memo = lpow(a,b/2);
    if(memo*memo > 1e6 || memo < 0){
      return -1;
    }
   return memo*memo;
 }else{
    ll memo = lpow(a,b-1);
    if(memo * a > 1e6 || memo < 0) return -1;
    return memo * a;
  } 
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



int main(void){
  ll n,k;cin>>n>>k;
  vector<ll> A;
  rep(i,n){
    ll a;cin>>a;
    A.push_back(a);
  }
  rep(i,n){
    ll a = A[i];
    ll new_a = 1;
    reps(p,sqrt(a+0.01)){
      if(p==1) continue;
      ll count = 0;
      while(a%p == 0){
        count++;
        a /= p;
      }
      count %= k;
      new_a *= lpow(p, count);
    }
    new_a *= a;
    A[i] = new_a;
  }

  map<ll,ll> ma;
  rep(i,n){
    ll a = A[i];
    if(ma.count(a) == 0){
      ma[a] = 0;
    }
    ma[a]++;
  }

  ll ans = 0;

  for(auto itr = ma.begin(); itr != ma.end(); itr++){
    ll a = (*itr).first;
    ll memo_a = a;
    ll a_num = (*itr).second;
    ll b = 1;
    reps(p,sqrt(a+0.01)){
      if(p==1) continue;
      ll count = 0;
      while(a%p == 0){
        count++;
        a /= p;
      }
      count %= k;
      b *= lpow(p, (k - count)%k);
      if(b > 1e6 || b < 0){
        b = -1;
        break;
      }
    }
    if(a != 1){
      b *= lpow(a, k - 1);
    }
    if(b < 0) continue;

    ll b_num = 0;
    if(ma.count(b) > 0){
      b_num = ma[b];
    }
    if(memo_a == b){
      ans += b_num * (b_num-1) / 2;
    }else if(memo_a < b){
      ans += a_num * b_num;
    }
  }
  cout<<ans<<endl;
  return 0;
}