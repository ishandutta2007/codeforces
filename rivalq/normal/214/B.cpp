//https://codeforces.com/contest/214/problem/B
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
  int n;
  cin>>n;
  vector<int> mod1,mod2;
  vector<int> arr;
  lop(i,n,1){
      int t;
      cin>>t;
      arr.pb(t);
      if(t%3==1) mod1.pb(arr[i]);
      else if(t%3==2) mod2.pb(arr[i]);
  }
  sort(all(arr),greater<int>()),sort(all(mod1)),sort(all(mod2));
  if(arr[n-1]!=0) cout<<-1<<endl;
  else if(arr[0]==0){cout<<0<<endl;ret;}
  else{
      int s=accumulate(all(arr),0);
      if(s%3==1){
          if(mod1.size()>0) {
              auto it=find(all(arr),mod1[0]);
              arr.erase(it);
          }
          else{
              if(mod2.size()>1){
              auto it1=find(all(arr),mod2[0]);
              auto it2=find(all(arr),mod2[1]);
              arr.erase(it1),arr.erase(it2);
              }
              else {cout<<-1<<endl;ret;}  
          }
    }
    if(s%3==2){
         if(mod2.size()>0) {
              auto it=find(all(arr),mod2[0]);
              arr.erase(it);
            }
        else{
            if(mod1.size()>1){
              auto it1=find(all(arr),mod1[0]);
              auto it2=find(all(arr),mod1[1]);
              arr.erase(it1),arr.erase(it2);
            }
            else {cout<<-1<<endl;ret;}
        }    
    }
    sort(all(arr),greater<int>());
   if(arr[0]==0) {cout<<0<<endl;ret;}
   for(int i=0;i<arr.size();i++){
       cout<<arr[i];
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