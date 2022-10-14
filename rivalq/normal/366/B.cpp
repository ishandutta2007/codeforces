//https://codeforces.com/contest/366/problem/b
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
  int n,k;cin>>n>>k;
  vector<int> v;
  lop(i,n,1) {int t;cin>>t;v.pb(t);}
  int mi=0,mie=1;
  lop(i,n,k)mi+=v[i];
  lop(i,k,1){
      int t_mi=0;
      for(int j=i;j<n;j+=k)t_mi+=v[j];
      if(t_mi<mi) {mi=t_mi;mie=i+1;}
  }
  cout<<mie<<endl;
}
int main(){
    IOS;
    ll t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}