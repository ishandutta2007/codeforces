//https://codeforces.com/contest/29/problem/B
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define eb emplace_back
#define pii pair<int,int>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define mod 1000000007
using namespace std;
int solve(){
  double l,d,v,r,g;
  cin>>l>>d>>v>>g>>r;
  double cycle=r+g;
  double time_d=d/v;
 double k= fmod(time_d,cycle);
  if(k>=g){
      time_d=time_d-k+cycle;
  }
  
  double time_l =time_d+(l-d)/v;
  cout<<fixed<<setprecision(10)<<time_l<<endl;
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