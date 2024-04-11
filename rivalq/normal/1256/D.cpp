//https://codeforces.com/contest/1256/problem/D
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
/***********void sieve(int isprime[],int n){
   memset(isprime,1,sizeof(isprime));
   for(int p=2;p*p<=n;p++){
       if(isprime[p]==1){
           for(int i=p*p;i<=n;i+=p){
               isprime[i]=0;
           }
       }
   }
}*********/
int solve(){
  int n;cin>>n;
  ll k;cin>>k;
  string s;
  cin>>s;
  ll i=1;
  ll c=0;
  while(s[c]=='0')c++;
  while(i<n && k>0){
      if(s[i]=='0' && s[i-1]!='0'){
          
          //while(k>0 && j>=0 && s[j]=='1')j--,k--;
          if(k>=i-c){
              s[c]='0';
              s[i]='1';
              k-=(i-c);
              c++;
          }
          else{
              s[i-k]='0';
              s[i]='1';
              break;
          }
          
      }
      i++;
  }
  cout<<s<<endl;
  ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    ret;
}