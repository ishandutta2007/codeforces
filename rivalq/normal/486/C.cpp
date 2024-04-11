//https://codeforces.com/problemset/problem/486/C
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
int solve(){
  int n,k;cin>>n>>k;  
  string s;cin>>s;
  int i=0;
  k--;
  int ans=0;
  int z=(n-1)/2;
  if(k<=z){
      int m1=0,m2=0;
      for(int i=k;i<=z;i++){
            if(s[i]!=s[n-i-1])m1=i-k; 
      }
      for(int i=k;i>=0;i--){
          if(s[i]!=s[n-i-1])m2=k-i;
      }
      ans+=(2*min(m1,m2)+max(m1,m2));
  }
  else{
      int m1=0,m2=0;
      for(int i=k;i<n;i++){
            if(s[i]!=s[n-i-1])m1=i-k; 
      }
      for(int i=k;i>z;i--){
          if(s[i]!=s[n-i-1])m2=k-i;
      }
      ans+=(2*min(m1,m2)+max(m1,m2));
      //cout<<ans<<endl;
  }
  for(int i=0;i<n;i++){
     if(s[i]!=s[n-i-1]){
         ans=ans+min(abs(s[i]-s[n-i-1]),26-abs(s[i]-s[n-i-1]));
         s[i]=s[n-i-1];
     }  
  }
  cout<<ans<<endl;
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