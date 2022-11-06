#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
#define RANGE(x) x.begin(),x.end()
void one(){
  
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  vector<int> b(n-1);
  vector<int> c(n);
  ll allways= 1;
  vector<int> cpre(n+1);
  cpre[0]=0;
  for(int i=0;i<n;++i){
    cin>>c[i];
    allways*=c[i];
    cpre[i+1]=cpre[i]+c[i];
    allways%=mod;
  }
  for(int i=1;i<n;++i){
    cin>>b[i-1];
  }
  int Q;
  //cin>>Q;
  vector<int> bbars(n);
  vector<int> bpre(n);
  bpre[0]=0;
  bbars[0]=0;
  for(int i=1;i<n;++i){
    bpre[i]=bpre[i-1]+b[i-1];
    bbars[i]=bbars[i-1]+bpre[i];
  }
  vector<vector<int>> good(n);
  good[0].resize(c[0]+1,1);
  for(int k=1; k<n;++k){
    good[k].resize(1+cpre[k+1]); 
    ll val = 0;
    for(int i=0;i<=cpre[k+1];++i){
      if(i>=c[k]+1)val-=good[k-1][i-c[k]-1];
      if(i<=cpre[k])val+=good[k-1][i];
      good[k][i] = val%mod;
    }
  }
  ll curr = 0;
  for(ll k : good[n-1]){
    curr+=k;
  }
  curr%=mod;
  //cout<<curr<<endl;
  cin>>Q;
  vector<pair<int,int>> qs(Q);
  vector<int> res(Q,0);
  for(int i =0 ;i<Q;++i){
    int x;
    cin>>x;
    qs[i] = make_pair(x,i);
  }
  sort(RANGE(qs));
  for(auto& p:qs){
    int x = p.first;
    // check to see if this breaks something
    bool recalc=false;
    for(int stop=0;stop<n;++stop){
      int check = bbars[stop]+ (stop+1)*x;
      // cout<<x<<" "<<stop<<" "<<check<<endl;
      if(check<0)continue;
      if(check>cpre[stop+1]){
        //result is 0
        goto allzero;
      }
      else if(good[stop][check]>0){
        // recalculate here
        recalc = true;
      }
    }
    if(recalc){
      //vector<vector<int>> good(n);
      //good[0].resize(c[0]+1,1+mod);
      int mi = bbars[0]+x;
      for(int i=0;i<mi;++i){
        good[0][i]=0;
      }
      for(int i=max(mi,0);i<=c[0];++i)good[0][i]=1+mod;
      for(int k=1; k<n;++k){
        ll val = 0;
        int stop = bbars[k]+x*(k+1);
        
        for(int i=0;i<=cpre[k+1];++i){
          if(i>=c[k]+1)val-=good[k-1][i-c[k]-1];
          if(i<=cpre[k])val+=good[k-1][i];
          good[k][i] = val%mod + (val==0?0:mod);
        }
        for(int j=0;j<min(stop,cpre[k+1]+1);++j)good[k][j]=0;
      }
      curr = 0;
      for(ll k : good[n-1]){
        //cout<<k<<endl;
        curr+=k;
      }
      curr%=mod;
    }
    res[p.second]=curr;
  }
  
 allzero: void(0);
  for(int i=0;i<Q;++i){
    cout<<res[i]<<endl;
  }
  cout<<flush;
}