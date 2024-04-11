#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000007;
int p(int A,int B){
  if(B<0)return 0;
  if(!B)return 1;
  if(B%2)return p(A,B-1)*A%mod;
  int C=p(A,B/2);
  return C*C%mod;
}
signed main(){
  int N;
  string S;
  cin>>N>>S;
  map<char,int> mp,mp2;
  for(char c:S)mp[c]++;
  int ans=0,p1=p(3,mp['?']),p2=p(3,mod-2);
  for(char c:S){
    mp[c]--;
    if(c=='b'){
      ans=(ans+mp2['a']*mp['c']%mod*p1%mod)%mod;
      ans=(ans+mp2['a']*mp['?']%mod*p1%mod*p2%mod)%mod;
      ans=(ans+mp2['?']*mp['c']%mod*p1%mod*p2%mod)%mod;
      ans=(ans+mp2['?']*mp['?']%mod*p1%mod*p(p2,2)%mod)%mod;
    }else if(c=='?'){
      ans=(ans+mp2['a']*mp['c']%mod*p1%mod*p2%mod)%mod;
      ans=(ans+mp2['a']*mp['?']%mod*p1%mod*p(p2,2)%mod)%mod;
      ans=(ans+mp2['?']*mp['c']%mod*p1%mod*p(p2,2)%mod)%mod;
      ans=(ans+mp2['?']*mp['?']%mod*p1%mod*p(p2,3)%mod)%mod;
    }
    mp2[c]++;
  }
  cout<<ans<<endl;
}