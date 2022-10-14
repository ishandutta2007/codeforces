//https://codeforces.com/problemset/problem/615/D
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define inarr(arr,n) lop(i,n,1)cin>>arr[i]
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define eb emplace_back
#define fr first
#define sc second
#define pii pair<int,int>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define hell 1000000007
using namespace std;
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
ll xymodp(ll x,ll y,ll p){
    ll a=1;
    x%=p;
    while(y){
        if(y&1)a=(a*x)%p;
        x=(x*x)%p;
        y/=2;
    }
    return a;
}

int solve(){
  int m;
  cin>>m;
  ll arr[m];inarr(arr,m);
  if(m==1){
      cout<<arr[0]<<endl;
      ret;
  }
  ll np=1;
  map<ll,ll> mp;
  ll c=1;
  lop(i,m,1){
      mp[arr[i]]++;
      np=(np*(arr[i]))%hell;
     
  }
  ll mas=1;
  ll po=1;
  for(auto i:mp){
   ll p=i.fr;
   ll y=i.sc;
   p=xymodp(p,po,hell);
   p=xymodp(p,y*(y+1)/2,hell);
   mas=xymodp(mas,y+1,hell);
   mas=(mas*p)%hell;
   po=po*(y+1)%(hell-1);
 }
 cout<<mas<<endl;
  ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}