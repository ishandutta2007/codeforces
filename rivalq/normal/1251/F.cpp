#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}
int xymodp(int x,int y,int p){
	if(y==0)return (x!=0);
    int a=1;
    x%=p;
    while(y){
        if(y&1)a=(a*x)%p;
        x=(x*x)%p;
        y/=2;
    }
    return a;
}
#undef hell
const int hell = 998244353;// used as hell
const int root = 565042129; // nth root of mod
const int root_1 = 950391366;// inverse of root
const int root_pw = 1 << 20; // value of n (goes till 2**23 as 998244353-1==119*2**23)
vector<int>st1(1<<20),st2(1<<20),st3(1<<20,1),mp(1<<20);
struct NTT{ 
   void fft(vector<int>&a,bool invert){
      int i,j,n=(int)a.size();
       for(i=1,j=0;i<n;++i){
          int bit=n>>1;
          for(;j>=bit;bit>>=1){
             j-=bit;
          }
          j+=bit;
          if(i<j) swap(a[i],a[j]);
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
  void multiply(const vector<int> &a,const vector<int> &b,vector<int> &res){
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
 }
    void polyexpo(vector<int>&a,vector<int>&st1,vector<int>&st2,int n1,int n2){
       int s=sz(a);    
       for(int i=0;i<s;i++)a[i]=xymodp(st1[i],n1,hell)*xymodp(st2[i],n2,hell)%hell;
       fft(a,1);
    }
}ntt;

vector<int>poly[6];
void func(int f1,int f2,int i){
	 poly[i].resize(1<<20);
	 if(f1 && f2)ntt.polyexpo(poly[i],st1,st2,f1,2*f2);
	 else if(f1)ntt.polyexpo(poly[i],st1,st3,f1,1);
	 else if(f2)ntt.polyexpo(poly[i],st3,st2,1,2*f2);
	 else ntt.polyexpo(poly[i],st3,st3,1,1);
}
void make(){
	 st1[0]=st1[1]=1;st1[1]++;
	 st2[0]=st2[1]=1;
	 ntt.fft(st1,0);
	 ntt.fft(st2,0);
}
int solve(){
 int n,k;cin>>n>>k;
 vector<int>a(n+1),b(k+1);
 rep(i,1,n+1)cin>>a[i];
 rep(i,1,k+1)cin>>b[i];
 sort(all(a));
 sort(all(b));
 int j=1;
 int f1=0,f2=0;
 for(int i=1;i<=k;i++){
    for(j;j<=n;j++){
    	if(a[j]>=b[i])break;
    	if(mp[a[j]]==1)f2++,f1--;
    	else if(mp[a[j]]==0)f1++;
    	mp[a[j]]++;
    }
    func(f1,f2,i);
 }
 int q;cin>>q;
 rep3(q){
 	int p;cin>>p;
 	int ans=0;
 	for(int i=1;i<=k;i++){
 		int val=p-2*b[i]-2;
 		if(val<0)continue;
 		ans=(ans+poly[i][val/2])%hell;
 	}
 	cout<<ans<<endl;
 }
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;//cin>>t;
    make();
    while(t--){
        solve();
    }
    return 0;
}