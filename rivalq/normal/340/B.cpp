//https://codeforces.com/contest/340/problem/B
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define mod 1000000007
using namespace std;
int  orie(int x1,int y1,int x2,int y2,int x3,int y3){
    return ((y3-y1)*(x1-x2)-(y1-y2)*(x3-x1));
}
double area(int x1,int y1,int x2,int y2,int x3,int y3){
    double k =abs(x1*y2+x2*y3+x3*y1-x2*y1-x3*y2-x1*y3);
    return k/2;
}
int solve(){
  int n;cin>>n;
  vector<pii> v;
  for(int i=0;i<n;i++){
      int x,y;cin>>x>>y;
      v.pb({x,y});
  }
 double ma3=0;
  for(int i=0;i<n;i++){
     for(int j=i+1;j<n;j++){
        int x1=v[i].first,y1=v[i].second,x2=v[j].first,y2=v[j].second;
        double ma1=0;
        for(int k=0;k<n;k++){
            if(orie(x1,y1,x2,y2,v[k].first,v[k].second)<0 && k!=i && k!=j){
              ma1=max(area(x1,y1,x2,y2,v[k].first,v[k].second),ma1);
            }
        }
        if(ma1==0)continue;
        double ma2=0;
         for(int k=0;k<n;k++){
            if(orie(x1,y1,x2,y2,v[k].first,v[k].second)>0 && k!=i && k!=j){
              ma2=max(area(x1,y1,x2,y2,v[k].first,v[k].second),ma2);
            }
        }
        if(ma2==0)continue;
        ma3=max(ma1+ma2,ma3);
        //cout<<ma1<<" "<<ma2<<endl;
     }
  }
  cout<<setprecision(12)<<ma3<<endl;
   
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