//https://codeforces.com/problemset/problem/490/C
#include<bits/stdc++.h>
#define rep1(i,n,a) for(int i=0;i<n;i+=a)
#define rep2(i,n,a) for(int i=a;i<n;i++)
#define rep3(n)     for(int x=0;x<n;x++)
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
int ch(string s,int i,int l,int r){
   if(s[i]=='0')return 0;
   ll re=0;
   for(int j=i;j<=l;j++){
       int k=s[j]-'0';
       re=(re+((k%r)*(xymodp(10,l-j,r)))%r)%r;
   }
   return re;
}
int solve(){
  string s;cin>>s;
  int a,b;cin>>a>>b;  
  int n=s.length();
  ll re=0;
  ll re2=ch(s,0,n-1,b);
  for(int i=0;i<n-1;i++){
   int k=s[i]-'0';
   re=(re*10+(k%a))%a;
   re2=(re2+b-(k%b)*xymodp(10,n-i-1,b)%b)%b;
   if(s[i+1]=='0')continue;
   //cout<<re<<" "<<re2<<endl;
   if(re==0 && re2==0){ 
      cout<<"YES"<<endl;
      rep3(i+1)cout<<s[x];cout<<endl;
      rep2(x,n,i+1)cout<<s[x];cout<<endl;
      ret;
      
   }  
  }
  //cout<<ch(s,0,4,97)<<endl;
  cout<<"NO"<<endl;
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