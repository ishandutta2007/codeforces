//https://codeforces.com/contest/99/problem/B
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
  int n;cin>>n;
 map<int,int> mp1,mp2;
 
  lop(i,n,1){
      int t;cin>>t;
      mp1.insert({t,i+1});
      if(mp2.count(t))mp2[t]++;
      else mp2.insert({t,1});
  }
  if(mp1.size()==1)cout<<"Exemplary pages.\n";
  else if(mp1.size()==2){
      int v1=0,v2=0,f1=0,f2=0;
      auto itr=mp2.begin();
      f1=itr->second,v1=itr->first;itr++;
      f2=itr->second,v2=itr->first;
      if(f1==f2 && f1==1){
          if(v1%2==v2%2){
              cout<<(v2-v1)/2<<" ml. from cup #"<<mp1[v1]<<" to cup #"<<mp1[v2]<<".\n"; 
          }
          else cout<<"Unrecoverable configuration.\n";
      }
      else cout<<"Unrecoverable configuration.\n";
  }
  else if(mp1.size()==3){
        auto itr=mp2.begin();
        int v1,v2,v3,f1,f2,f3;
        f1=itr->second,v1=itr->first;itr++;
        f2=itr->second,v2=itr->first;itr++;
        f3=itr->second,v3=itr->first;
        if(f1==f3 && f1==1 && 2*v2==v1+v3){
            cout<<(v2-v1)<<" ml. from cup #"<<mp1[v1]<<" to cup #"<<mp1[v3]<<".\n"; 
        }
        else cout<<"Unrecoverable configuration.\n";
  }
  else cout<<"Unrecoverable configuration.\n";
 
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