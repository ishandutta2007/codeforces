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
#include <bitset>
#include <functional>
#include <cassert>
using namespace std;
#define fast_io ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
#define ll long long int
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=1; i<=(int)(n); i++)
#define REP(i,n) for(int i=n-1; i>=0; i--)
#define REPS(i,n) for(int i=n; i>0; i--)
#define MOD (long long int)(1e9+7)
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
  if(n <= 1e7){
    ret *= kaijo(n); ret %= MOD;
    ret *= gyaku_kaijo(r); ret %= MOD;
    ret *= gyaku_kaijo(n-r); ret %= MOD;
  }else{
    rep(i,r){
      ret *= n-i; ret %= MOD;
      ret *= mpow(r-i, MOD-2); ret %= MOD;
    }
  }
  return ret;
}

int ranking[2002][2002] = {};
int number[2002][2002] = {};
int back[2002][2002] = {};

int main(void){
  fast_io
  cout<<fixed<<setprecision(15);

  bool seg[10][7] = {
    {1,1,1,0,1,1,1},
    {0,0,1,0,0,1,0},
    {1,0,1,1,1,0,1},
    {1,0,1,1,0,1,1},
    {0,1,1,1,0,1,0},
    {1,1,0,1,0,1,1},
    {1,1,0,1,1,1,1},
    {1,0,1,0,0,1,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1}
  };

  ranking[0][0] = 1;
  int n,k;cin>>n>>k;
  //
  rep(i,n){
    string s; cin>>s;reverse(all(s));
    bitset<7> bs(s);
    vector<pair<ll,ll>> v;
    rep(j,k+1){
      if(ranking[i][j] != 0){
        v.push_back({ranking[i][j], j});
      }
    }
    sort(all(v));
    int R = 1;
    rep(vi, v.size()){
      int j = v[vi].second;
      //
      REP(num,10){
        int count = 0;
        bool ok = true;
        rep(t,7){
          //target
          if(!seg[num][t] && bs[t]){
            ok = false;
            break;
          }
          if(seg[num][t] && !bs[t]){
            count++;
          }
        }
        if(!ok) continue;
        /*if(num == 9 && i == 0){
          cout<<count<<endl;
          cout<<bs<<endl;
        }*/
        if(j + count > k) continue;
        if(ranking[i+1][j+count] == 0){
          ranking[i+1][j+count] = R;
          back[i+1][j+count] = j;
          number[i+1][j+count] = num;
          R++;
        }
      }
    }
  }
  if(ranking[n][k] == 0){
    cout<<-1<<endl;
    return 0;
  }
  int now = k;
  vector<int> ans;
  REPS(i,n){
    ans.push_back(number[i][now]);
    now = back[i][now];
  }
  REP(i,ans.size()){
    cout<<ans[i];
  }
  cout << endl;
  /*rep(j,k+1){
    if(ranking[1][j] == 0 ) continue;
    cout<<j << " " << ranking[1][j]<<" " << number[1][j]<<endl;
  }*/
  return 0;
}