//https://codeforces.com/problemset/problem/387/B
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
  int n,m;ll t;
  cin>>n>>m;
  ll  a[n],b[m];
  int vi[n]={0};
  lop(i,n,1){
    cin>>t;
    a[i]=t;
  }
  lop(i,m,1){
      cin>>t;
      b[i]=t;
  }
  lop(i,m,1){
      t=b[i];
    int l=0,u=n,ans=0,f=0;
    while(l<=u){
        int mid=(l+u)/2;
        if(a[mid]==t){
           ans=mid;f=1;
           break;
        }
        if(a[mid]>t){
            u=mid-1;
        }
        else{
            l=mid+1;
            f=1;ans=mid;
        }
        
        }
        if(f){
        for(int j=ans;j>=0;j--){
            if(vi[j]==0){vi[j]=1;break;}
    }}
   
  }
  int c=0;
 lop(i,n,1){
     if(vi[i]==0) c++;
 }
 cout<<c<<endl;
  
}
int main(){
    IOS;
    ll t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    ret;
}