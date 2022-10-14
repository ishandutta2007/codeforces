//https://codeforces.com/problemset/problem/26/A
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
void sieve(int isprime[],int n){
   lop(i,n+1,1)isprime[i]=i;
   for(int p=2;p*p<=n;p++){
       if(isprime[p]){
           for(int i=p*p;i<=n;i+=p){
               isprime[i]=0;
           }
       }
   }
}
int solve(){
  int isprime[3001];
  sieve(isprime,3000);
  vector<int> v;
  rep(i,3001,2){
      if(isprime[i])v.pb(i);
  }
  //for(auto j:v)cout<<j<<" ";  
  int n;cin>>n;
  int cnt=0;
  for(int i=1;i<=n;i++){
      int t=0;
      int k=i;
       for(auto j:v){
          if(t>2)break;
          if(j>i)break;
          if(i%j==0){
              t++;
              while(i%j==0)i=i/j;
          }
      }
      if(t==2)cnt++;
      i=k;
  }
  cout<<cnt<<endl;
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