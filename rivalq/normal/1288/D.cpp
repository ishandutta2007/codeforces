//https://codeforces.com/contest/1288/problem/D
#include<bits/stdc++.h>
#define rep1(i,n,a) for(int i=0;i<n;i+=a)
#define rep2(i,n,a) for(int i=a;i<n;i++)
#define rep3(n)     for(int i=0;i<n;i++)
#define inarr(arr,n) rep1(i,n,1)cin>>arr[i]
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define trav(a,x) for(auto x:a)
#define endl "\n"
#define eb emplace_back
#define fr first
#define sc second
#define gcd(a,b) __gcd(a,b)
#define pres(a,x) a.find(x)!=a.end()
#define sz(a) (int)a.size()
#define pii pair<int,int>
#define psi pair<string,int>
#define pss pair<string,string>
#define pll pair<ll,ll>
#define vec vector<int>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define hell 1000000007
#define narak 998244353
const int inf1=1e9;
const ll inf2=1e18;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
// syntax for min priority_queue of pairs
// priority_queue<pair<ll,ll>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
int i1,i2;
int arr[300001][8];
int n,m;
int ch(int mid){
  map<int,int> mp;
  for(int i=0;i<n;i++){
      int t=0;
      for(int j=0;j<m;j++){
        if(arr[i][j]>=mid)t+=(1<<(m-j-1));
      }
      //if(pres(mp,t))continue;
      //cout<<t<<endl;
      mp[t]=i;
  }
  for(auto i:mp){
      for(auto j:mp){
          if((i.fr|j.fr)==(pow(2,m)-1)){
              i1=i.sc+1;
              i2=j.sc+1;
              return 1;
          }
      }
  }
  return 0;
}
int solve(){
 cin>>n>>m;
  int ma=0;
  rep1(i,n,1){
      rep1(j,m,1)cin>>arr[i][j],ma=max(ma,arr[i][j]);
  }
  int u=inf1;
  int l=0;
  int cnt=0;
  while(l<=u){
      int mid=(l+u)/2;
      if(ch(mid))l=mid+1;
      else u=mid-1;
  }
  //cout<<l<<endl;
  cout<<i1<<" "<<i2<<endl;
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