//https://codeforces.com/contest/594/problem/D
#pragma GCC optimize "trapv" 
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
#define ret            return 0
#define pi             3.1415926536
#define hell           1000000007
#define narak          998244353
const int inf1=1e9;
const ll inf2=1e18;
const int N=200010;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
int isprime[1000001];
vector<int>primes;
void sieve(int isprime[],int n){
   rep3(n+1)isprime[i]=i;
   for(int p=2;p*p<=n;p++){
       if(isprime[p]){
           primes.pb(p);
           for(int i=0;i<primes.size() and primes[i]*p<=n;i++){
                isprime[p*primes[i]]=0;
                if(p%primes[i]==0)break;
           }
       }
   }
}
ll A[N];
ll pre[N];
int ans[N];
vector<pii> V[N];
int last[1000000];
ll bit[N];
ll inverse[1000000];
ll inv1[1000000];
ll inv2[1000000];
struct query{
    int l,r,id;
    bool operator<(const query &rhs){
        return r<rhs.r;
    }
}q[N];
void func(int n){
    for(int i=1;i<=n;i++){
      int val=A[i];
        for(auto j:primes){
           if(j*j>val)break;
           int cnt=0;
           while(val%j==0)val/=j,cnt++;
           if(cnt)V[i].eb(j,cnt);
      }
      if(val>1)V[i].eb(val,1);
    }
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
ll get(ll BIT[],int i){
    ll sum=1;
    while(i){
        sum=sum*BIT[i]%hell;
        i-=i&(-i);
    }
    return sum;
}
void upbit(ll BIT[],int i,int n,ll val){
    while(i<=n){
        BIT[i]=BIT[i]*val%hell;
        i+=i&(-i);
    }
}
int solve(){
 mem1(last);   
 int n;cin>>n;           
 rep3(n)cin>>A[i+1];
 pre[0]=1;
 rep(i,1,n+1)pre[i]=pre[i-1]*A[i]%hell;
 func(n);
 int m;cin>>m;
 rep3(m){
     cin>>q[i].l>>q[i].r;
     q[i].id=i;
 }
 sort(q,q+m);
 for(int i=0;i<=N;i++)bit[i]=1;
 int j=0;
 for(int i=1;i<=n;i++){
   for(auto p:V[i]){
       upbit(bit,i,n,inv1[p.x]);
       if(last[p.x]!=-1){
           upbit(bit,last[p.x],n,inv2[p.x]);
       }
       last[p.x]=i;
   }  
   while(j<m && q[j].r==i){
     int l=q[j].l,r=q[j].r;
     ll val=pre[r]*xymodp(pre[l-1],hell-2,hell)%hell;
     val=val*get(bit,r)%hell*xymodp(get(bit,l-1),hell-2,hell)%hell;
     ans[q[j].id]=val;
     j++;
   }
 }
 rep3(m)cout<<ans[i]<<endl;
 ret;
}
int main(){
    IOS;
    sieve(isprime,1000000);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    inverse[0]=0;
    inverse[1]=1;
    for(int i=2;i<=1000000;i++)inverse[i]=inverse[hell%i]*(hell-hell/i)%hell;
    for(int i=2;i<=1000000;i++)inv1[i]=(i-1)*inverse[i]%hell;
    for(int i=2;i<=1000000;i++)inv2[i]=i*inverse[i-1]%hell;
    #ifdef cat
    cat();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}