//https://codeforces.com/contest/437/problem/B
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
  int s,l;
  cin>>s>>l;
  vector<pair<int,int>> v;
  for(int i=1;i<=l;i++){
      int k=0;int t=i;
      while(t%2==0){k++;t/=2;}
      v.pb({pow(2,k),i});
  }
 
  set<int> se;
  
  sort(all(v),greater<pair<int,int>>());int i=0;
  int on=ceil((float)l/2);
  int be=l/2;
  while(s>on && i<be){
      if(s>v[i].first){
          s-=v[i].first;
          se.insert(v[i].second);

      }
      i++;
  }
  if(s>on)cout<<-1<<endl;
  else{
      int j=0;
      while(j<s){
          se.insert(2*j+1);j++;
      }
      s=0;
  }
  
  
      

if(s==0){
cout<<se.size()<<endl;
for(auto i:se){
    cout<<i<<" ";
}}}
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