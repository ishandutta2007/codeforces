//https://codeforces.com/contest/189/problem/B
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
  ll w,h;
  ll ws=0,hs=0;
  cin>>w>>h;
  //ll ma=max(w,h);
  ll mi=max(w,h);
  if(mi&1)mi--;
  for(int i=2;i<=mi;i+=2){
     ws+=(w>=i)?w-i+1:0;
     hs+=(h>=i)?h-i+1:0;
  }
  cout<<ws*hs<<endl;
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