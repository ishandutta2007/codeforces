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

int main(void){
  fast_io
  cout<<fixed<<setprecision(15);

  int r,c;cin>>r>>c;
  vector<vector<bool>> B, OK;
  rep(y,r){
    B.push_back(vector<bool>());
    OK.push_back(vector<bool>(c, true));
    rep(x,c){
      char s; cin>>s;
      if(s == '.'){
        B[y].push_back(false);
      }else if(s == '#'){
        B[y].push_back(true);
      }else{
        assert(false);
      }
    }
  }

  rep(y,r){
    bool ren = false;
    int count = 0;
    rep(x,c){
      if(B[y][x]){
        if(ren){

        }else{
          ren = true;
          count++;
        }
      }else{
        ren = false;
      }
    }
    if(count >= 2){
      cout << -1 << endl;
      return 0;
    }else if(count == 1){
      rep(x,c){
        OK[y][x] = false;
      }
    }
  }

  rep(x,c){
    bool ren = false;
    int count = 0;
    rep(y,r){
      if(B[y][x]){
        if(ren){

        }else{
          ren = true;
          count++;
        }
      }else{
        ren = false;
      }
    }
    if(count >= 2){
      cout << -1 << endl;
      return 0;
    }else if(count == 1){
      rep(y,r){
        OK[y][x] = false;
      }
    }
  }

  rep(y,r){
    int count = 0;
    rep(x,c){
      if(OK[y][x] || B[y][x]) count++;
    }
    if(count == 0){
      cout << -1 << endl;
      return 0;
    }
  }

  rep(x,c){
    int count = 0;
    rep(y,r){
      if(OK[y][x] || B[y][x]) count++;
    }
    if(count == 0){
      cout << -1 << endl;
      return 0;
    }
  }

  vector<bool> checked[1005];
  rep(y,r){
    checked[y] = vector<bool>(c, false);
  }

  int ans = 0;
  rep(y,r){
    rep(x,c){
      if(!checked[y][x] && B[y][x]){
        ans++;
        //cerr << y << " " << x << endl;
        checked[y][x] = true;
        queue<Pii> q;
        q.push({y,x});
        while(q.size() > 0){
          int yy = q.front().first;
          int xx = q.front().second;
          q.pop();
          for(int dy = -1; dy <= 1; dy++){
            for(int dx = -1; dx <= 1; dx++){
              if(abs(dy) + abs(dx) != 1) continue;
              if(yy+dy < r && yy+dy >= 0 && xx+dx < c && xx+dx >= 0){
                if(checked[yy+dy][xx+dx]) continue;
                if(!B[yy+dy][xx+dx]) continue;
                checked[yy+dy][xx+dx] = true;
                q.push({yy+dy, xx+dx});
              }
            }
          }
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}