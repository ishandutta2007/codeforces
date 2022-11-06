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


int main(void){
  int n;
  cin>>n;
  map<ll,ll> mp;
  rep(i,n){
    ll a;
    cin>>a;
    if(mp.count(a) == 0){
      mp[a] = 0;
    }
    mp[a]++;
  }
  vector<pair<ll,ll>> nums;
  for(auto itr = mp.begin(); itr != mp.end(); itr++){
    nums.push_back({itr->second, itr->first});
  }
  sort(all(nums));
  int ni = 0;
  ll ans = 0, ans_h=-1;
  ll sum = 0;
  for(ll h=1; h<sqrt(n)+10; h++){
    while(ni < nums.size() && nums[ni].first < h){
      sum += nums[ni].first;
      ni++;
    }
    ll col = (sum + (nums.size()-ni)*h)/h;
    //cout<<h<<" "<<col<<endl;
    if(col < h) continue;
    if(ans < h*col){
      ans = h*col;
      ans_h = h;
    }
  }

  reverse(all(nums));
  vector<vector<ll>> ANS;
  rep(i,ans_h){
    ANS.push_back(vector<ll>());
    rep(j,ans/ans_h){
      ANS[i].push_back(0);
    }
  }
  rep(i,nums.size()){
    if(nums[i].first > ans_h){
      nums[i].first = ans_h;
    }
  }

  ni = 0;
  rep(j,ans/ans_h){
    rep(i,ans_h){
      ANS[i][j] = nums[ni].second;
      nums[ni].first--;
      if(nums[ni].first == 0) ni++;
    }
  }
  
  cout<<ans<<endl;
  cout<<ans_h<<" "<<ans/ans_h<<endl;
  rep(i,ans_h){
    rep(j,ans/ans_h){
      cout<<ANS[i][(j-i+ans/ans_h)%(ans/ans_h)]<<" ";
    }
    cout<<endl;
  }
  return 0;
}