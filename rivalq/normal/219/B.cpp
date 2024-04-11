//https://codeforces.com/contest/219/problem/B
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
ll unsigned po(ll i){
    if(i==0) return 1;
    return 10*po(i-1);
}
int solve(){
  ll unsigned p,d;
  cin>>p>>d;
  ll i=0;
  while(d>0 && po(i)<p){
      int k=((p/(ll)po(i))%10);
      if(k!=9){
      if(d>=po(i)*(k+1)){
          p-=(po(i)*(k+1));
          d-=(po(i)*(k+1));
      }
      else d=0;
      }
      i++;
  }
  cout<<p<<endl;
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