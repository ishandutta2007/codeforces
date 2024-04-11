#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 31607;
const int teninv = 3973;
#define RANGE(x) x.begin(),x.end()
static int p[21][21];
static int N;
static int c[21];
static int r[1<<21][21];
static int fullbm;
void setupc(){
  for(int i=0;i<N;++i){
    int v = 1;
    for(int j=0;j<N;++j){
      v*=p[i][j];
      v%=mod;
    }
    c[i] = v;
  }
}
void setupr(){
  for(int i=0;i<N;++i){
    r[0][i] = 1;
  }
  for(int j=1;j< (1<<N); ++j){
    int t = 1;
    int minv = 0;
    while( (t & j) == 0) {
      t*=2;
      ++minv;
    }
    for(int i=0;i<N;++i){
      r[j][i] = (p[minv][i]*r[j-t][i])%mod;
      //cout<<j<<" "<<i<<" "<<r[j][i]<<endl;
    }
  }
}
void setup(){setupr();setupc();}
void solve(int& res, int cprod, int cv, int bm,int cs){
  if(cv==N){
    int diff = 1;
    for(int i=0;i<N;++i){
      diff *= 1-r[fullbm-bm][i];
      diff %= mod;
    }
    //    if(bm==0)diff -= 1;
    diff*=cs*cprod;
    diff %=mod;
    //cout<<res<<" "<<cprod<<" "<<cv<<" "<<bm<<" "<<diff<<endl;
    res= (res+diff)%mod;
    return;
  }
  solve(res,cprod,cv+1,bm,cs);
  solve(res,(cprod*c[cv])%mod,cv+1,bm|(1<<cv),-cs);
}
void one(){
  cin>>N;
  fullbm = (1<<N)-1;
  for(int i=0;i<N;++i){
    for(int j=0;j<N;++j){
      int z;
      cin>>z;
      //z=5000;
      p[i][j]= z*teninv %mod;
      // cerr<<p[i][j]<<" ";
    }
    //cerr<<endl;
  }
  
  
  int res = 1;
  setup();
  solve( res,1,0,0,-1);
  // do diags
  vector<int> diag1(N);
  int sp = 1;
  for(int i=0;i<N;++i){
    diag1[i]=p[i][i];
    sp*=p[i][i];
    sp%=mod;
    p[i][i] = 1;
  }
  setup();
  solve(res,sp,0,0,1);
  // once without main diag
  // once with main diag
  sp = 1;
  for(int i=0;i<N;++i){
    p[i][i]=diag1[i];
    //diag[i] = p[i][N-1-i];
    sp*=p[i][N-1-i];
    sp%=mod;
    p[i][N-1-i] = 1;
  }
  setup();
  solve(res,sp,0,0,1);
  for(int i=0;i<N;++i){
    // p[i][i]=diag[i];
    //diag[i] = p[i][N-1-i];
    sp*=p[i][i];
    sp%=mod;
    p[i][i] = 1;
  }
  setup();
  solve(res,sp,0,0,-1);
  
  cout<<(res+mod)%mod<<endl;
  // sum over all set
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  one();  
  cout<<flush;
}