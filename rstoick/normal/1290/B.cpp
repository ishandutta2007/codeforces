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

typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

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

  string s;cin>>s;
  int n = s.size();
  vector<int> ans(n);
  int ruiseki[n+1][26];
  rep(i,26){
    ruiseki[0][i] = 0;
  }
  rep(i,n){
    rep(j,26){
      if(s[i] - 'a' == j){
        ruiseki[i+1][j] = ruiseki[i][j] + 1;
      }else{
        ruiseki[i+1][j] = ruiseki[i][j];
      }
    }
  }
  int bi = 0, ei = 0;
  while(bi < n){
    while(ei < n && s[bi] == s[ei]) ei++;
    while(bi < n && bi < ei){
      ans[bi] = ei-1;
      bi++;
    }
  }

  int q;cin>>q;
  rep(_t, q){
    int l,r;cin>>l>>r;l--;r--;
    if(l==r){
      cout<<"Yes"<<endl;
      continue;
    }
    if(s[l] != s[r]){
      if(r <= ans[l]){
        cout<<"No"<<endl;
      }else{
        cout<<"Yes"<<endl;
      }
    }else{
      int count = 0;
      rep(j,26){
        if(ruiseki[r+1][j] - ruiseki[l][j] > 0){
          count++;
        }
      }
      //cout<<count<<endl;
      if(count >= 3){
        cout<<"Yes"<<endl;
      }else{
        cout<<"No"<<endl;
      }
    }

  }
  return 0;
}