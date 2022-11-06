#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define RANGE(x) x.begin(),x.end()
const ll mod = 1000000007;
ll modpow(int k){
  if(k==0)return 1;
  ll d = modpow(k/2);
  ll p = (d*d)%mod;
  return k%2?p*2%mod:p;
}
void one(){
  int N;
  cin>>N;
  vi vals(N);
  for(int i=0;i<N;++i)cin>>vals[i];

  // Sum of k consecutive numbers is
  // k odd:  kn for any n
  // k even: k/2 (2k+1) (fixed odd)

  // odd even :  an = b/2 odd
  // n = b/2
  // odd even even n = sum(even/2), get odds
  
  // even even: same power of 2
  // if two smallest are same power of 2?
  
  vector<int> powdivs(32,0);
  powdivs[0]=1;//offset that any can be fine
  for(int a: vals){
    ++powdivs[__builtin_ctz(a)];
  }
  ll res = 0; 
  for(int i=0;i<32;++i){
    
    if(powdivs[i]>=1){
      // cout<<i<<" "<<powdivs[i]<<endl;

      int m = powdivs[i];
      //ways to pick an even number of them
      
      ll p = modpow(m-1)-1;
      int pow = 0;
      for(int j=i+1;j<32;++j){
        pow+=powdivs[j];
      }
      res+=modpow(pow)* p %mod;
      res%=mod;
    }
  }
  cout<<res<<endl;
  
  // a
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TC = 1;
  //  cin>>TC;
  while(TC-->0){
    one();
  }
  cout<<flush;
}