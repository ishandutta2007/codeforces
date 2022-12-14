#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

// mod
const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

// floating
typedef double Real;
const Real EPS = 1e-11;
#define EQ0(x) (abs(x)<EPS)
#define EQ(a,b) (abs(a-b)<EPS)
typedef complex<Real> P;

int n;
int a[525];
int k;
int b[525];
int sp[525];
int rd[525];
int dp[525][525];
int bef[525][525];

void dfs(int l,int r){
  int p = bef[l][r];
  if(p==-1){
    return;
  }else{
    dfs(l,p);
    dfs(p+1,r);
    if(dp[l][p] > dp[p+1][r]){
      printf("%d R\n",rd[l]);
    }else{
      printf("%d L\n",rd[p+1]);
    }
    FOR(i,l+1,n)rd[i]--;
  }
}

int main(){
  scanf("%d",&n);
  REP(i,n)scanf("%d",a+i);
  scanf("%d",&k);
  REP(i,k)scanf("%d",b+i);
  // check it is legal sequence
  int iter = 0;
  REP(i,k){
    int sum = 0;
    while(iter<n && sum<b[i]){
      sum += a[iter++];
    }
    if(sum != b[i]){
      puts("NO");
      return 0;
    }
    sp[i] = iter;
  }
  if(iter!=n){
    puts("NO");
    return 0;
  }
  REP(i,n)rd[i] = i+1;
  REP(i,k){
    int beg = (i>0?sp[i-1]:0);
    int len = sp[i]-beg;
    REP(j,len)REP(k,len)dp[beg+j][beg+k]=bef[beg+j][beg+k]=-1;
    REP(j,len)dp[beg+j][beg+j]=a[beg+j];
    FOR(l,2,len+1)REP(j,len){
      int x = j+l-1;
      if(x>=len)continue;
      REP(w,l-1){
        int p = j+w;
        if(dp[beg+j][beg+p]!=-1 && dp[beg+p+1][beg+x]!=-1 && dp[beg+j][beg+p]!=dp[beg+p+1][beg+x]){
          dp[beg+j][beg+x] = dp[beg+j][beg+p]+dp[beg+p+1][beg+x];
          bef[beg+j][beg+x] = beg+p;
          break;
        }
      }
    }
    if(dp[beg+0][beg+len-1]==-1){
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  REP(i,k){
    int beg = (i>0?sp[i-1]:0);
    int len = sp[i]-beg;
    dfs(beg,beg+len-1);
  }
  return 0;
}