//https://codeforces.com/contest/114/problem/B
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
int n,m,ma=0;
map<string,int> mp;
map<int,string> mp2;
int arr[17][17];
set<string> mt;

void dfs(set<string> s){
  if(ma<s.size()){
      ma=s.size();
      mt=s;

  }
    for(int i=1;i<=n;i++){
        if(s.find(mp2[i])==s.end()){
         int q=1;
         for(auto j:s){
             if(arr[mp[j]][i]){q=0;break;}
         } 
         if(q){  
         set<string> sd=s;
         sd.insert(mp2[i]);
          dfs(sd);
         }
        
        }
        
    }
    return ;
}
int solve(){
  cin>>n>>m;
   for(int i=1;i<=n;i++){
      string t;cin>>t;
      mp.insert({t,i});
      mp2.insert({i,t});
  }
  int conf[n+1]={0};
  lop(i,n+1,1){
      lop(j,n+1,1)arr[i][j]=0;
  }
  lop(i,m,1){
      string s1,s2;cin>>s1>>s2;
      arr[mp[s1]][mp[s2]]=1;
      arr[mp[s2]][mp[s1]]=1;
      conf[mp[s1]]=1,conf[mp[s2]]=1;
  }
  set<string> s;
 // s.insert(mp2[1]);
 for(int i=1;i<=n;i++){
     if(conf[i]==0) s.insert(mp2[i]);
 }
  if(m)
  {dfs(s);
  cout<<ma<<endl;
  for(auto i:mt)cout<<i<<endl;}
  else{
      cout<<n<<endl;
      for(auto i:mp) cout<<i.first<<endl;
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