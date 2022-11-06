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

vector<int> G[(int)(5*1e5+3)];
pair<ll,ll> ans[(int)(5*1e5+3)];
bool checked[(int)(5*1e5+3)];
int children_n[(int)(5*1e5+3)], child_n[(int)(5e5+3)]; 
ll n;

int count_child(int now){
  if(checked[now]) return 0;
  checked[now] = true;
  ll count = 0;
  rep(j, G[now].size()){
    int next = G[now][j];
    count += count_child(next);
  }
  child_n[now] = G[now].size() - 1;
  children_n[now] = count;
  return count + 1;
}

bool saiki(int now, int l, int r_sum){
  if(checked[now]) return false;
  checked[now] = true;
  ans[now] = {l, l+r_sum+2+child_n[now]};
  ll r = ans[now].second; r--;
  ll child_sum = 0;
  REP(j, G[now].size()){
    int next = G[now][j];
    if(!saiki(next, r, child_sum)) continue;
    child_sum += children_n[next]*2 + 2;
    r--;
  }
  return true;
}

int main(void){
  scanf("%lld", &n);
  rep(i,n-1){
    int a,b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  rep(i,n){
    checked[i] = false;
    child_n[i] = 0;
    children_n[i] = 0;
  }
  count_child(0);
  child_n[0] += 1;
  rep(i,n){
    checked[i] = false;
  }
  saiki(0, 1, -1);
  rep(i,n){
    printf("%lld %lld\n", ans[i].first, ans[i].second);
  }
  /*rep(i,n){
    cout<<i<<" "<<child_n[i]<<" "<<children_n[i]<<endl;
  }*/
  return 0;
}