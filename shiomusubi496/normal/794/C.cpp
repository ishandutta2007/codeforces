#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  string s,t; cin>>s>>t;
  sort(s.begin(),s.end());
  sort(t.begin(),t.end());
  int n=s.size();
  string ans;
  for(int i=0,a=0,b=0;i<n;i++){
    if(t[n-1-b]<=s[a]){
      for(int j=n-1;j>=i;j--){
        if(j%2==0)ans+=s[a++];
        else ans+=t[n-1-(b++)];
      }
      cout<<ans<<endl;
      return 0;
    }
    if(i%2==0)ans+=s[a++];
    else ans+=t[n-1-(b++)];
  }
  cout<<ans<<endl;
}