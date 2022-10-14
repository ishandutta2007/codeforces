//https://codeforces.com/contest/312/problem/B
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
  double a,b,c,d;
  cin>>a>>b>>c>>d;
  double r=(1-a/b)*(1-c/d);
  cout<<setprecision(12)<<(a/b)/(1-r)<<endl;
}
int main(){
    IOS;
    ll t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}