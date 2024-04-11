//https://codeforces.com/contest/233/problem/B
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
/*ll isq(ll n){
    ll u=n-1,l=0;
    ll unsigned mid;
    while(l<=u){
        mid=(l+u)/2;
        if(mid*mid==n) return mid;
        else if(mid*mid>n) u=mid-1;
        else l=mid+1;
    }
    return 0;
}*/
int dsum(ll x){
    int t=0;
    while(x!=0){
        t+=x%10;x/=10;
    }
    return t;
}
int solve(){
  ll n;
  cin>>n;
  int s=82;
  int arr[s]={0};
  for(int i=1;i<=s-1;i++){
     long double  k=sqrtl(4*n+i*i);
      if(floor(k)==ceil(k)) arr[i]=k;
  }
  //lop(i,s-1,1) cout<<i<<" "<<arr[i]<<endl;
  cout<<endl;
  for(int i=1;i<=s-1;i++){
      if(arr[i]){
          if((arr[i]-i)%2==0){
              ll x=(arr[i]-i)/2;
              if(dsum(x)==i){
                cout<<x<<endl;
                ret;
              }
              
          }
          
      }
  }
  cout<<-1<<endl;

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