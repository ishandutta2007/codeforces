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

vector<int> G[1001];
bool exist[1001];
bool checked[1001];
/*
void find_leaf(int now, vector<int>& leafs){
  int count = 0;
  checked[now] = true;
  rep(j, G[now].size()){
    int next = G[now][j];
    if(!exist(next)) continue;
    if(checked[next]) continue;
    count++;
    find_leaf(next, leafs);
  }
  if(count == 0){
    leafs.push_back(now);
  }
}

void init_checked(int n){
  reps(i,n){
    checked[i] = false;
  }
}*/

int main(void){
  fast_io
  cout<<fixed<<setprecision(15);

  int n;cin>>n;
  rep(i,n-1){
    int a,b;cin>>a>>b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  rep(t, n/2){
    vector<int> leafs;
    reps(i,n){
      if(G[i].size() == 1){
        leafs.push_back(i);
      }
    }
    cout<<"?"<<" "<<leafs[0]<<" "<<leafs[1]<<endl;
    cout.flush();
    int a;cin>>a;
    if(leafs[0] == a || leafs[1] == a){
      cout<<"!"<<" "<<a<<endl;
      cout.flush();
      return 0;
    }

    int x = leafs[0]; int y = leafs[1];
    int nx = G[x][0];
    int ny = G[y][0];
    G[x].clear();
    G[y].clear();
    rep(j,G[nx].size()){
      if(G[nx][j] == x){
        G[nx].erase(G[nx].begin() + j);
        break;
      }
    }
    rep(j,G[ny].size()){
      if(G[ny][j] == y){
        G[ny].erase(G[ny].begin() + j);
        break;
      }
    }
    if(t == n/2 - 1){
      cout<<"!"<<" "<<a<<endl;
      cout.flush();
      return 0;
    }
  }


  /*
  reps(i,n){
    exist[i] = true;
  }*/

  /*
  while(true){
    //
    int root = -1;
    reps(i,n){
      if(exist[i]){
        root = i;
        break;
      }
    }
    init_checked(n);
    //
    vector<int> leafs;
    find_leaf(root, leafs);

    //

    //

    //,  

    //1
  }*/
  return 0;
}