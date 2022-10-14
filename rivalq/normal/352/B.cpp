//https://codeforces.com/contest/352/problem/B
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
  int  n;cin>>n;
  vector<pair<int,int>> v;
  lop(i,n,1){
      int t;cin>>t;
      v.pb({t,i});
  }
  sort(all(v));
  int c=0;
  vector<pair<int,int>> a;
  int i=0;
  while(i<n){
      int cu=v[i].first;
      int it=i;
      if(i+2<n &&v[i+2].first==cu){
          while(v[it].first==cu) it++;
          int f=1;int d=v[i+1].second-v[i].second;
          for(int j=i;j<it-1;j++){
              if(v[j+1].second-v[j].second!=d) {f=0;break;}
          }
          if(f) a.pb({cu,d});
          i=it;
          
      }
      else{
          if(i<n-1&&v[i+1].first==cu)
          a.pb({cu,v[i+1].second-v[i].second}),i+=2;
          else
          a.pb({cu,0}),i++;
      }
  }
  n=a.size();
  cout<<n<<endl;
 lop(i,n,1){
     cout<<a[i].first<<" "<<a[i].second<<endl;
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