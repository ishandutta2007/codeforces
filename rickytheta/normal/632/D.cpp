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

int n,m;
int a[1252521];
int b[1252521];
int e[1252521];
const int INF = 1000000000;

int main(){
  scanf("%d%d",&n,&m);
  REP(i,n)scanf("%d",a+i);
  REP(i,n)b[i]=(a[i]<=m?a[i]:INF);
  sort(b,b+n);
  int ed = lower_bound(b,b+n,INF)-b;
  REP(i,ed) e[b[i]]++;
  REP(_i,m){
    int i = m-_i;
    int t = i+i;
    while(t<=m){
      e[t]+=e[i];
      t+=i;
    }
  }
  int reslen = 0;
  int reslcm = 1;
  REPR(i,m+1){
    if(e[i]>reslen){
      reslen = e[i];
      reslcm = i;
    }
  }
  printf("%d %d\n",reslcm,reslen);
  REP(i,n)if(reslcm%a[i]==0)printf("%d ",i+1);
  printf("\n");
  return 0;
}