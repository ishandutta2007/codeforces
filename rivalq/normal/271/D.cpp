//https://codeforces.com/problemset/problem/271/D
#include<bits/stdc++.h>
#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep(i,a,n)cin>>arr[i]
#define ll             long long int
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define IOS            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pi             3.1415926536
#define hell           1000000007
#define narak          998244353
const int inf1=1e9;
const ll inf2=1e18;
const int N=100000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
#include <unistd.h> // not included in bits/stdc++.h
unsigned ll mix(unsigned ll a, unsigned ll b, unsigned ll c){
    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
}
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
struct polyhash{
   ll *hash1;
   ll *hash2;
   ll base1,base2; 
   ll  hell1,hell2;
   polyhash(int n){
       hash1=new ll[n+10];
       hash2=new ll[n+10];
       unsigned ll seed = mix(clock(), time(NULL), getpid());
       srand(seed);
       base1=299;
       base2=rand()%2000+31;
       hell1=hell;
       hell2=rand()*rand()%800000000+200000009;
       hash1[0]=hash2[0]=1;
       rep(i,1,n+10) hash1[i]=(hash1[i-1]*base1)%hell1;
       rep(i,1,n+10) hash2[i]=(hash2[i-1]*base2)%hell2;
   }
   ll gethash(int i,int j,ll dp[]){
      ll k=dp[j];
      if(i>0)k-=dp[i-1];
      k=(k+hell1)%hell1;
   return (k*(xymodp(hash1[i],hell1-2,hell1)))%hell1;
}
}poly1(2000);
void init(int n,ll dp[],string &s){
  ll val=0;
  for(int i=0;i<n;i++){
      val=(val+(s[i]*poly1.hash1[i])%poly1.hell1)%poly1.hell1;
      dp[i]=val;
  }
}
int solve(){
  string s;
  cin>>s;
  map<int,int> mp;
  rep3(26){
      char c;cin>>c;
      c='1'-c;
      mp[i+97]=c;
  } 
  int k;cin>>k;
  int n=s.length();
  ll cnt=0;  
  ll dp[n]={0};
  init(n,dp,s); 
  for(int l=1;l<=n;l++){
    set<ll> st;  
     int b=0;
     for(int i=0;i<l;i++){
         b+=mp[s[i]];
     }
     if(b<=k)st.insert(poly1.gethash(0,l-1,dp));
     int j=l;
     int i=0;
     while(j<n){
         b-=mp[s[i]];
         b+=mp[s[j]];
         i++;j++;
         if(b<=k)st.insert(poly1.gethash(i,i+l-1,dp)); 
     }
     cnt+=st.size();
  }          
  cout<<cnt<<endl;
 return 0;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    cat();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
}