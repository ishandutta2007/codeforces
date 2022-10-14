#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define inarr(arr,n) lop(i,n,1)cin>>arr[i]
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define eb emplace_back
#define fr first
#define sc second
#define pii pair<int,int>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define hell 1000000007
using namespace std;
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
int solve(){
  int arr[6]={4,8,15,23,16,42};
  int sum=12+15+23+16+42;
  map<int,pii> mp;
  for(int i=0;i<6;i++){
      for(int j=i+1;j<6;j++){
          mp.insert({arr[i]*arr[j],{arr[i],arr[j]}});
          //cout<<arr[i]*arr[j]<<" ";
      }
  }
  cout<<"? 1 2"<<endl;
  cout<<flush;
  int pro;cin>>pro;
  int a=mp[pro].fr; 
  int b=mp[pro].sc;
  cout<<"? 2 3"<<endl;
  cout<<flush;
  int pro2;cin>>pro2;
  int c=mp[pro2].fr;
  int d=mp[pro2].sc;
  int ans[6]={0};
  if(c==a || c==b){
      if(c==a) {
          // means a on 2,b on 1 d on 3;
          ans[0]=b;
          ans[1]=a;
          ans[2]=d;
         
      }
      else{
          // means b on 2 a on 1 d on 3;
          ans[0]=a;
          ans[1]=b;
          ans[2]=d;
         
      }
  }
  else{
      if(d==a){
         // means a on 2 , b on 1 c on 3;
          ans[0]=b;
          ans[1]=a;
          ans[2]=c;
          

      }
      else{
          // means b on 2 , a on 1,c on 3; 
          ans[0]=a;
          ans[1]=b;
          ans[2]=c;
      }
  }
   cout<<"? 1 4"<<endl;
          cout<<flush;
          int pro3;cin>>pro3;
          ans[3]=pro3/ans[0];
          cout<<"? 1 5"<<endl;
          cout<<flush;
          int pro4;cin>>pro4;
          ans[4]=pro4/ans[0];
          ans[5]=sum-ans[0]-ans[1]-ans[2]-ans[3]-ans[4];
          cout<<"! ";
          for(auto i:ans)cout<<i<<" ";cout<<endl;
          cout<<flush;

  ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}