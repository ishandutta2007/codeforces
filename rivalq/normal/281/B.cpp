//https://codeforces.com/contest/281/problem/B
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define ll long long  int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define mod 1000000007
using namespace std;
int solve(){
  int x,y;
  int n;
  cin>>x>>y>>n;
  int a=0,b=1;
      for(int d=1;d<=n;d++){
       ll d1=abs((ll)x*b*d-(ll)y*a*d);
       int a1=(ll)x*d/y;
       int a2=a1+1;
       ll t1=abs((ll)x*d*b-(ll)a1*y*b);
       ll t2=abs((ll)x*b*d-(ll)a2*y*b);
       if(d1>t1){
           a=a1,b=d,d1=t1;
       }
       if(d1>t2) a=a2,b=d,d1=t2;
    }
    
    cout<<a<<"/"<<b<<endl;  
  

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