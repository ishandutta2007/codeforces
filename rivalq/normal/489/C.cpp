//https://codeforces.com/contest/489/problem/C
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
/***********Sieve of Primes********/
/***********void sieve(int isprime[],int n){
   memset(isprime,1,4*n);
   for(int p=2;p*p<=n;p++){
       if(isprime[p]==1){
           for(int i=p*p;i<=n;i+=p){
               isprime[i]=0;
           }
       }
   }
}*********/
/***********************TO generate Bitmasks of length N ******************/
/************void BITMASKING(string vis,int j){
      
      if(j==n)return;
      string s1=vis;
      s1[j]='1';
      if(j==n-1){
          mp1.pb(s1);
          mp1.pb(vis);
          return ;
      }
      else{
      dfs(vis,j+1);
      dfs(s1,j+1);
      }
}****************/
int solve(){
  int m,s;
  cin>>m>>s;
  int mi=m;
  int ma=9*m;
  if(s>ma)cout<<"-1 -1"<<endl;
  else if(s==0 && m>1)cout<<"-1 -1"<<endl;
  else{
      int marr[m]={0},miarr[m]={0};
      int k=s;
      int i=0;
      while(k){
         marr[i]=min(9,k);
         k-=min(9,k);
         i++;
      }
      k=s-1;
      i=m-1;
      while(k){
          miarr[i]=min(9,k);
          k-=min(9,k);
          i--;
      }
      miarr[0]++;
      for(auto i:miarr)cout<<i;
     cout<<" ";
     for(auto i:marr)cout<<i;


  }
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