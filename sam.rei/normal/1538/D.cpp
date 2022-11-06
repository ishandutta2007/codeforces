#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define RANGE(x) x.begin(),x.end()

vector<int> primes;
void one(){
  int a,b,k;
  cin>>a>>b>>k;
  if(k==1){
    if(a%b==0){
      if(a==b)cout<<"NO\n";
      else cout<<"YES\n";
    }else{
      if(b%a==0){
	cout<<"YES\n";
      }
      else cout<<"NO\n";
    }
    return;
  }
  int ac=0,bc=0;
  for(int i:primes){
    if(i>a)break;
    while(a%i==0){
      ++ac;
      a/=i;
    }
  }
  if(a>1)++ac;
  for(int i:primes){
    if(i>b)break;
    while(b%i==0){
      ++bc;
      b/=i;
    }
  }
  if(b>1)++bc;
  
  cout<<(ac+bc>=k?"YES\n":"NO\n");
}
int main(){
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int lim = 31622;
  vector<bool> prime(lim,true);
  for(int i=2;i<lim;++i){
    if(!prime[i])continue;
    primes.push_back(i);
    for(int j=i*i;j<lim;j+=i){
      prime[j]=false;
    }
  }
  int TC;
  cin>>TC;
  while(TC-->0){
    one();
  }
  cout<<flush;
}