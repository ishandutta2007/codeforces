#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod=998244353;
int E[1000010];
signed main(){
  E[0]=E[1]=1;
  for(int i=2;i<1000010;i++){
    if(E[i])continue;
    for(int j=i;j<1000010;j+=i) E[j]=i;
  }
  int n; cin>>n;
  int sum=0;
  for(int i=1;i<=n;i++){
    map<int,int>mp;
    for(int j=i;E[j]!=1;j/=E[j]) mp[E[j]]++;
    int cnt=1;
    for(auto[a,b]:mp)cnt*=b+1;
    if(i==n)return cout<<(sum+cnt)%mod<<endl,0;
    (sum+=sum+cnt)%=mod;
  }
}