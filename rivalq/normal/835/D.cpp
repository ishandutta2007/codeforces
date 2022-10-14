//https://codeforces.com/contest/835/problem/D
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
ll dp[5001];
ll arr[5001];
ll suff[5001];
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
       base1=rand()%2000+29;
       base2=rand()%2000+31;
       hell1=hell;
       hell2=rand()*rand()%800000000+200000009;
       hash1[0]=hash2[0]=1;
       rep(i,1,n+10) hash1[i]=hash1[i-1]*base1%hell1;
       rep(i,1,n+10) hash2[i]=hash2[i-1]*base2%hell2;
   }
   void compute(string &s){
       int n=s.length();
       dp[0]=s[0];
       for(int i=1;i<n;i++){
           dp[i]=(dp[i-1]+s[i]*hash1[i])%hell1;
       }
       suff[n-1]=s[n-1];
       for(int i=n-2;i>=0;i--){
           suff[i]=(suff[i+1]+s[i]*hash1[n-1-i])%hell1;
       }
   }
   void solve(string &t){
       int n=t.length();
       ll hp1=0,hs1=0;
       ll hp2=0,hs2=0;
       for(int i=0;i<n;i++){
           ll ans=0; 
           hp1=(hp1+(t[i]*hash1[i])%hell1)%hell1;
           hs1=((hs1*base1)%hell1+t[i])%hell1;
           hp2=(hp2+(t[i]*hash2[i])%hell2)%hell2;
           hs2=((hs2*base2)%hell2+t[i])%hell2;
           if(hp1==hs1 && hp2==hs2){ 
             if(i==0){
                 ans=1;
                 dp[0]=1;
             }
             else{
                ans=(1+dp[(i+1)/2-1]);
                dp[i]=(1+dp[(i+1)/2-1]);
             }
             arr[dp[i]]++;
           }
           //cout<<ans<<endl; 
       }
   }


}poly1(5010);
int solve(){
 string s;cin>>s;
 int n=s.length();
 for(int i=0;i<n;i++){
    memset(dp,0,sizeof(dp));  
    string t=s.substr(i,n-i);
    poly1.solve(t);
 }
 for(int i=n-1;i>0;i--){
     arr[i]=arr[i]+arr[i+1];
 }
 for(int i=1;i<=n;i++)cout<<arr[i]<<" ";cout<<endl;
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
    return 0;
}