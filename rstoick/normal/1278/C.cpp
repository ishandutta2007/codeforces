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

int main(void){
  fast_io
  ll t;cin>>t;
  rep(t_,t){
    ll n;cin>>n;
    vector<int> left,right,ansL,ansR;
    ll memoL=0, memoR=0;
    ll c1=0,c2=0;
    rep(i,n){
      int a;cin>>a;
      if(a==1){
        c1++;
      }else{
        c2++;
      }
      left.push_back(a);
    }
    reverse(all(left));
    rep(i,n){
      int a;cin>>a;
      if(a==1){
        c1++;
      }else{
        c2++;
      }
      right.push_back(a);
    }

    int many;
    if(c1 < c2){
      many = 2;
    }else if(c1 > c2){
      many = 1;
    }else{
      cout<<0<<endl;
      continue;
    }
    ansL.push_back(0);
    ansR.push_back(0);
    rep(i,n){
      if(left[i] == many){
        memoL++;
      }else{
        memoL--;
      }
      if(ansL.size() == memoL){
        ansL.push_back(i+1);
      }
    }
    rep(i,n){
      if(right[i] == many){
        memoR++;
      }else{
        memoR--;
      }
      if(ansR.size() == memoR){
        ansR.push_back(i+1);
      }
    }

    ll ans = LINF;
    rep(i,ansL.size()){
      if(abs(c1-c2) - i >= ansR.size() || abs(c1-c2) - i < 0) continue;
      chmin(ans, ansL[i] + ansR[abs(c1-c2) - i]);
    }
    cout<<ans<<endl;
  }
  return 0;
}