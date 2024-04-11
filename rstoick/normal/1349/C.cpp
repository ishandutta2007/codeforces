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
#define MOD (long long int)(998244353)
#define INF (int)(1123456789)
#define LINF (long long int)(1e18+9)
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

ll dist[1000][1000] = {};

int main(void){
  fast_io
  cout<<fixed<<setprecision(15);

  ll r,c,t;
  cin>>r>>c>>t;
  vector<string> S;
  rep(i,r){
    string s; cin>>s;
    S.push_back(s);
  }

  queue<Pii> q;
  rep(y,r){
    rep(x,c){
      bool ok = false;
      if(y-1 >= 0 && S[y][x] == S[y-1][x]) ok = true;
      if(y+1 < r && S[y][x] == S[y+1][x]) ok = true;
      if(x-1 >= 0 && S[y][x] == S[y][x-1]) ok = true;
      if(x+1 < c && S[y][x] == S[y][x+1]) ok = true;
      if(!ok){
        dist[y][x] = LINF;
        continue;
      }

      q.push({y,x});
      dist[y][x] = 0;
    }
  }

  while(q.size() > 0){
    queue<Pii> q2;
    while(q.size() > 0){
      int y = q.front().first;
      int x = q.front().second;
      q.pop();
      if(y-1 >= 0 && dist[y-1][x] == LINF){
        dist[y-1][x] = dist[y][x] + 1;
        q2.push({y-1,x});
      }
      if(y+1 < r && dist[y+1][x] == LINF){
        dist[y+1][x] = dist[y][x] + 1;
        q2.push({y+1,x});
      }
      if(x-1 >= 0 && dist[y][x-1] == LINF){
        dist[y][x-1] = dist[y][x] + 1;
        q2.push({y,x-1});
      }
      if(x+1 < c && dist[y][x+1] == LINF){
        dist[y][x+1] = dist[y][x] + 1;
        q2.push({y,x+1});
      }
    }

    q = q2;
  }

  rep(_t,t){
    ll y,x,k;cin>>y>>x>>k;
    y--;x--;
    if(dist[y][x] >= k){
      cout << S[y][x] << "\n";
      continue;
    }
    if((k - dist[y][x]) % 2 == 0){
      cout << S[y][x] << "\n";
    }else{
      if(S[y][x] == '0'){
        cout << "1\n";
      }else{
        cout << "0\n";
      }
    }
  }
  return 0;
}