#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int t;cin>>t;
  while(t--){
    int n;cin>>n;
    vector<int>A(2*n);
    for(int&i:A)cin>>i;
    sort(A.begin(),A.end());
    for(int i=0;i<2*n-1;i++){
      map<int,int>mp;
      for(int i=0;i<2*n;i++)mp[A[i]]++;
      int x=prev(mp.end())->first;
      if(!--mp[x])mp.erase(prev(mp.end()));
      vector<pair<int,int>>ans{{x,A[i]}};
      if(!--mp[A[i]])mp.erase(mp.find(A[i]));
      for(int i=0;i<n-1;i++){
        int a=prev(mp.end())->first;
        if(!--mp[a])mp.erase(prev(mp.end()));
        if(mp.count(x-a)){
          if(!--mp[x-a])mp.erase(mp.find(x-a));
          ans.push_back({x-a,a});
          x=max(x-a,a);
        }else goto home;
      }
      puts("YES");
      cout<<ans[0].first+ans[0].second<<endl;
      for(auto[a,b]:ans)cout<<a<<' '<<b<<endl;
      goto home2;
      home:;
    }
    puts("NO");
    home2:;
  }
}