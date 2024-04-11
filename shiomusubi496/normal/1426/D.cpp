#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int N;
  cin>>N;
  vector<int> A(N);
  for(int &i:A)cin>>i;
  map<int,int> mp;
  vector<pair<int,int>> B;
  mp[0]=0;
  int sum=0;
  for(int i=0;i<N;i++){
    sum+=A[i];
    if(mp.count(sum))B.push_back({i+1,mp[sum]+1});
    mp[sum]=i+1;
  }
  sort(B.begin(),B.end());
  int idx=-1,ans=0;
  for(pair<int,int> p:B)
    if(idx<=p.second){
      idx=p.first;
      ans++;
    }
  cout<<ans<<endl;
}