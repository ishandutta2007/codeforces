//https://codeforces.com/contest/31/problem/B
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define mod 1000000007
using namespace std;
int solve(){
  string s;cin>>s;
  int n=s.length();
  if(s[0]=='@'||s[n-1]=='@')cout<<"No solution\n";
  else{
      vector<int> v;
      for(int i=0;i<n;i++){
          if(s[i]=='@')v.pb(i);
      }
      if(v.size()==0)cout<<"No solution\n";
      else{
          int mi=100;
          for(int i=1;i<v.size();i++){
              mi=min(mi,v[i]-v[i-1]);
          }
          if(mi<3)cout<<"No solution\n";
          else{
           vector<string> ans;
           int i=0;
           string t="";
           while(i<n){
             if(s[i]!='@')t+=s[i],i++;
             else{
                 t=t+s[i]+s[i+1];
                 ans.pb(t);
                 t="";
                 i=i+2;
             }
           }
           int n=ans.size();
           ans[n-1]+=t;
           for(int i=0;i<n;i++){
               if(i==0)cout<<ans[0];
               else cout<<","<<ans[i];
           }
           cout<<endl;
          }
      }
  }
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ll t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}