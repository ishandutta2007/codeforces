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

int n,k;
int a,b,c,d;
int pth[1252];

void swapp(int x,int y){
  REP(i,n){
    if(pth[i]==x)pth[i]=y;
    else if(pth[i]==y)pth[i]=x;
  }
}

int main(){
  cin>>n>>k>>a>>b>>c>>d;
  if(n==4 || k<n+1){
    puts("-1");
    return 0;
  }
  --a;--b;--c;--d;
  REP(i,n)pth[i]=i;
  swapp(pth[0],a);
  swapp(pth[1],c);
  swapp(pth[n-2],d);
  swapp(pth[n-1],b);
  REP(i,n)pth[i]++;

  printf("%d",pth[0]);
  REPR(i,n)printf(" %d",pth[i]);
  printf("\n");

  printf("%d %d",pth[1],pth[0]);
  FOR(i,2,n-2)printf(" %d",pth[i]);
  printf(" %d %d\n",pth[n-1],pth[n-2]);
  return 0;
}