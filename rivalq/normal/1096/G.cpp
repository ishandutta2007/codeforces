//https://codeforces.com/contest/1096/problem/G
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
const int N=100000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
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
#undef hell
#define int long long
const int hell = 998244353;// used as hell
const int root = 565042129; // nth root of mod
const int root_1 = 950391366;// inverse of root
const int root_pw = 1<<20; // value of n (goes till 2**3 as 998244353-1==119*2**23)
struct NTT{ 
   void fft(int a[],bool invert,int n){
      int i,j;
       for(i=1,j=0;i<n;++i){
          int bit=n>>1;
          for(;j>=bit;bit>>=1){
             j-=bit;
          }
          j+=bit;
          if(i<j)swap(a[i],a[j]);
       }
       for(int len=2;len<=n;len<<=1){
          int wlen=invert?root_1:root;
           for(i=len;i<root_pw;i<<=1){
              wlen=(wlen*wlen%hell);
           }
        for(i=0;i<n;i+=len){
            int w=1;
            for(j=0;j<len/2;++j){
                int u=a[i+j],v=(int)(a[i+j+len/2]*w%hell);
                a[i+j]=(u+v+hell)%hell;
                a[i+j+len/2]=(u-v+hell)%hell;
                w=(w*wlen%hell);
            }
        }
    }
      if(invert){
        int nrev=xymodp(n,hell-2,hell);
        for(i=0;i<n;++i){
            a[i]=(a[i]*nrev%hell);
         }
      }
   }
  /**void multiply(const vector<int> &a,const vector<int> &b,vector<int> &res){
    vector<int> fa(a.begin(),a.end()),fb(b.begin(),b.end());
    size_t n=1;
    while(n<max(a.size(),b.size())) n<<=1;
    n<<= 1;
    fa.resize(n),fb.resize(n);
    fft(fa,false),fft(fb,false);
    for(size_t i=0;i<n;++i){
        fa[i]*=fb[i];
    }
    fft(fa,true);
    res.resize(n);
    for(size_t i=0;i<n;++i){
        res[i]=fa[i];
    }
 }**/
 void polyexpo(int a[],int n,int s){   
    fft(a,0,s);
    for(int i=0;i<s;i++)a[i]=xymodp(a[i],n,hell);
    fft(a,1,s);
 }
}ntt;
#undef int
ll poly[1<<20];
int solve(){
  int n,k;cin>>n>>k;          
  rep3(k){
      int t;cin>>t;
      poly[t]=1;
  }
  ntt.polyexpo(poly,n/2,1<<20);
  ll ans=0;
  rep3(1<<20){
      ans=(ans+(poly[i]*poly[i])%hell)%hell;
  } 
  cout<<ans<<endl;         
 ret;
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
    ret;
}