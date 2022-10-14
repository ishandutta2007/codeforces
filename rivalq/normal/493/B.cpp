//http://codeforces.com/problemset/problem/493/B
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
using namespace std;
int solve(){
  int n;ll t;
  cin>>n;
  ll p1[n]={0},p2[n]={0};
 ll pp1=0,pp2=0;ll m=0,o=0;
  lop(i,n,1){
   cin>>t;
   if(t>0) {pp1+=t;p1[m]=t;m++;}
   else {pp2+=-t;p2[o]=-t;o++;}
  }
  if(pp1>pp2){cout<<"first";}
  else if(pp2>pp1){cout<<"second";}
  else{
      
      lop(i,min(m,o),1){
          if(p1[i]>p2[i]){cout<<"first";ret;}
          if(p1[i]<p2[i]){cout<<"second";ret;}
      }
      if(m==o){
          if(t>0) cout<<"first";
          else cout<<"second";
          ret;
      }
      if(m>o){cout<<"first";}
      else cout<<"second";
  }
}
int main(){
    IOS;
    ll t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}