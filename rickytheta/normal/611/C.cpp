#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef complex<double> P;
typedef pair<int,int> pii;
#define REP(i,n) for(ll i=0;i<n;++i)
#define REPR(i,n) for(ll i=1;i<n;++i)
#define FOR(i,a,b) for(ll i=a;i<b;++i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define MOD (ll)(1e9+7)
#define ADD(a,b) a=((a)+(b))%MOD
#define FIX(a) ((a)%MOD+MOD)%MOD

int main(){
  int w,h;
  cin>>h>>w;
  vector<vi> mp(w,vi(h));
  REP(j,h){
    string s;
    cin>>s;
    REP(i,w) mp[i][j] = (int)(s[i]=='.');
  }
  vector<vi> yoko(w,vi(h,0)), tate(w,vi(h,0));
  // 
  REP(i,w-1)REP(j,h){
    yoko[i][j] = mp[i][j] & mp[i+1][j];
  }
  REPR(i,w)REP(j,h)yoko[i][j]+=yoko[i-1][j];
  REP(i,w)REPR(j,h)yoko[i][j]+=yoko[i][j-1];
  // 
  REP(i,w)REP(j,h-1){
    tate[i][j] = mp[i][j] & mp[i][j+1];
  }
  REPR(i,w)REP(j,h)tate[i][j]+=tate[i-1][j];
  REP(i,w)REPR(j,h)tate[i][j]+=tate[i][j-1];

  // REP(_i,w){
  //   DEBUG_VEC(mp[_i]);
  // }
  // REP(_i,w){
  //   DEBUG_VEC(yoko[_i]);
  // }
  // REP(_i,w){
  //   DEBUG_VEC(tate[_i]);
  // }

  int q;
  cin>>q;
  while(q--){
    int sx,sy,tx,ty;
    cin>>sy>>sx>>ty>>tx;
    --sx; --sy; --tx; --ty;
    int result = 0;
    if(tx>0)result += yoko[tx-1][ty];
    if(sx>0)result -= yoko[sx-1][ty];
    if(tx>0 && sy>0)result -= yoko[tx-1][sy-1];
    if(sx>0 && sy>0)result += yoko[sx-1][sy-1];
    if(ty>0)result += tate[tx][ty-1];
    if(sy>0)result -= tate[tx][sy-1];
    if(ty>0 && sx>0)result -= tate[sx-1][ty-1];
    if(sx>0 && sy>0)result += tate[sx-1][sy-1];
    cout<<result<<endl;
  }
  return 0;
}