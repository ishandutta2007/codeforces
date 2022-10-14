//https://codeforces.com/contest//problem/
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
vector<string> bitm;
void dfs(string vis,int j,int n){
      
      if(j==n)return;
      string s1=vis;
      s1[j]='1';
      if(j==n-1){
          bitm.pb(s1);
          bitm.pb(vis);
          return ;
      }
      else{
      dfs(vis,j+1,n);
      dfs(s1,j+1,n);
      }
}
int solve(){
  string vis="";
  string s;cin>>s;
  int j=s.length();
  //while(n/pow(10,j))j++;
  //j--;

  //j=2
  for(int i=0;i<j;i++)vis+="0";
  dfs(vis,0,j);   
  sort(all(bitm));
  //for(auto i:bitm)cout<<i<<" ";cout<<endl;
  int sum=pow(2,j)-2;
  string s2="";
  reverse(all(s));
  for(int i=0;i<j;i++){
      if(s[i]=='4')s2+='0';
      else s2+='1';
  }
  reverse(all(s2));
  //cout<<s2<<endl;
  int in=0;
  for(int i=0;i<bitm.size();i++){
    if(bitm[i]==s2){
      in=i;
      break;
    }
  }  
    cout<<sum+in+1<<endl;
  

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