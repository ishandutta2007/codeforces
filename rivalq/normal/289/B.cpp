//https://codeforces.com/contest/289/problem/B
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
int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
int solve(){
  int n,m,d;
  cin>>n>>m>>d;int k=n*m;
  int arr[k],darr[k-1];
  lop(i,k,1) cin>>arr[i];
  sort(arr,arr+k);
  rep(i,k-1,0) darr[i]=arr[i+1]-arr[i];
  if(k>1){
  int t=gcd(darr[0],darr[1]);
  rep(i,k-1,2){
      t=gcd(t,darr[i]);
   }
   if(t%d==0){
       int j=arr[k/2];
       ll c=0;
       lop(i,k,1){
           c+=abs(j-arr[i])/d;
       }
       cout<<c<<endl;
   }
   else cout<<-1<<endl;
  }
  else cout<<0<<endl;
}
int main(){
    IOS;
    ll t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}