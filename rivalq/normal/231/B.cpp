//https://codeforces.com/contest/231/problem/B
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
  int n,d,l;
  cin>>n>>d>>l;
  if(l==1){
      if(d==(n+1)/2-n/2){
          for(int i=0;i<n;i++) cout<<l<<" ";
      }
      else cout<<-1<<endl;
  }
  else{
      int arr[n]={0};
      for(int i=0;i<n;i++){
          if(i&1) arr[i]=l;
          else arr[i]=1;
      }
      int max=((n+1)/2)*l-n/2;
      int min=(n+1)/2 -(n/2)*l;
      if(d>max || d<min)cout<<-1<<endl;
      else{
          int di=d-min;
          int i=0;
          while(di>0){
              if(i&1){
                  if(di>(l-1)) arr[i]=1,di-=(l-1),i++;
                  else arr[i]-=(di),di=0;
              }
              else{
                   if(di>(l-1)) arr[i]=l,di-=(l-1),i++;
                   else arr[i]+=di,di=0;
              }
          }
          for(int i=0;i<n;i++){
              cout<<arr[i]<<" ";
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