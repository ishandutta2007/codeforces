//https://codeforces.com/contest/190/problem/B
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
  long double x1,y1,r1,x2,y2,r2;
  cin>>x1>>y1>>r1>>x2>>y2>>r2;
  long double k1=sqrtl((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
  long double k2=(r1+r2)/2;
  long double k3=k1/2-k2;
  if(abs(r1-r2)>k1) k3=(abs(r1-r2)-k1)/2;
  else if(k3<0)k3=0;
  cout<<fixed<<setprecision(10)<<k3<<endl;
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