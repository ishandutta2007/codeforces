//https://codeforces.com/contest/56/problem/B
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
  int sarr[n+1]={0};
  lop(i,n+1,1)sarr[i]=i;
  int arr[n+1]={0};
  lop(i,n,1){
        cin>>arr[i+1];
  }
  int l=1,r=n,f=0;
  for(int i=1;i<=n;i++){
      if(arr[i]!=sarr[i]){l=i,f=1;break;}
  }
  for(int i=n;i>0;i--){
      if(arr[i]!=sarr[i]){r=i,f=1;break;}
  }
  if(f==0)cout<<"0 0"<<endl;
  else{
      int s=l,e=r;
      while(s<=e){
          arr[s]=arr[e]+arr[s]-(arr[e]=arr[s]);
          s++,e--;
      }
      int q=0;
      for(int i=1;i<=n;i++){
          if(arr[i]!=sarr[i]){q=1;break;}
      }
      if(q)cout<<"0 0"<<endl;
      else cout<<l<<" "<<r<<endl;
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