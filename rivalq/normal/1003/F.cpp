//https://codeforces.com/contest/1003/problem/F
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
       hell1=rand()*rand()%800000000+200000007;
       hell2=rand()*rand()%800000000+200000009;
       hash1[0]=hash2[0]=1;
       rep(i,1,n+10) hash1[i]=hash1[i-1]*base1%hell1;
       rep(i,1,n+10) hash2[i]=hash2[i-1]*base2%hell2;
   }
   ll generator(string &s){
       int n=s.length();
       ll val=0;
       rep3(n){
           val=(val+s[i]*hash1[i])%hell1;
       } 
       return val;
   }
   
}poly1(100005);
int solve(){
   int n;cin>>n; 
   int leng=n-1;        
   string a[n];rep3(n){
       string t;cin>>t;
       a[i]=t;
       leng+=a[i].length();
   }
   ll hashes[n];  
   rep3(n){
       ll h=poly1.generator(a[i]);
       hashes[i]=h;
   }
  map<vector<ll>,vector<pii>>mp;
   for(int i=0;i<n;i++){
       vector<ll> v;
       for(int j=i;j<n;j++){
        v.pb(hashes[j]);
        mp[v].push_back({j,i});   
       }
   }
   int mi=leng;
   for(auto i:mp){
       if(i.y.size()<2)continue;
       sort(all(i.y));
       int l=i.y[0].y;
       int r=i.y[0].x;
       int len=r-l;
       for(int j=l;j<=r;j++){
           int s=a[j].length();
           len=len+s-1;
       }
       int cnt=0;
       int last=-1;
       for(auto j:i.y){
          if(last<j.y){
              cnt++;
              last=j.x;
          } 
       }
       if(cnt<2)continue;
       int t=leng-len*cnt;
       mi=min(t,mi);
   }
   cout<<mi<<endl;
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