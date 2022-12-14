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

int n;
int t[5025];
// 0~i, count of j
int bmp[5025][5025];
int ans[5025];
int dom[5025][5025];

int cand[4];

int main(){
  scanf("%d",&n);
  REP(i,n)scanf("%d",t+i);
  REP(i,n)--t[i];
  REP(i,n)REP(j,n){
    if(i>0)bmp[i][j]=bmp[i-1][j];
    if(j==t[i])bmp[i][j]++;
  }
  REP(i,n){
    ans[t[i]]++;
    dom[i][i]=t[i];
  }
  FOR(len,2,n+1){
    REP(i,n-len+1){
      int x = dom[i][i+len-2];
      int y = dom[i+1][i+len-1];
      cand[0] = x;
      cand[1] = y;
      cand[2] = t[i];
      cand[3] = t[i+len-1];
      sort(cand,cand+4);
      int win = -1;
      int wcnt = 0;
      REP(j,4){
        int k = cand[j];
        int cnt = bmp[i+len-1][k];
        if(i>0)cnt -= bmp[i-1][k];
        if(cnt>wcnt){
          wcnt = cnt;
          win = k;
        }
      }
      dom[i][i+len-1] = win;
      ans[win]++;
    }
  }
  //
  // REP(i,n){
  //   REP(j,n)printf("%5d",dom[i][j]);
  //   puts("");
  // }
  //
  printf("%d",ans[0]);
  REPR(i,n)printf(" %d",ans[i]);
  printf("\n");
  return 0;
}