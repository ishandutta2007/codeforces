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
int n,m,k;
// optimized version of  fft(iterative)
#define base         complex<double>
#define pi           3.141592653589793238  
// fft->true=inverse fft
// fft->false=direct fft 
void fft(vector<base> &a,bool direction){
   if(sz(a)==1)return;
   int n=sz(a);
   for(int i=1,j=0;i<n;i++){
    int bit=n>>1;
    for(;j>=bit;bit>>=1)j-=bit;
    j+=bit;
    if(i<j)swap(a[i],a[j]);
   }
   // original vector {ao,a1,a2,a3,a4.....}
   // now vector will look like {a0,a2,a4...|a1,a3,a5,a7...}
   for (int d=2;d<=n;d<<=1){
        double ang=2*pi/d*(direction?-1:1);
        base wd(cos(ang),sin(ang));
        for(int i=0;i<n;i+=d) {
            base w(1);
            for (int j=0;j<d/2;++j) {
                base u=a[i+j],v=a[i+j+d/2] * w;
                a[i+j]=u+v;
                a[i+j+d/2]=u-v;
                w*=wd;
            }
        }
    }
    if(direction){
        for(int i=0;i<n;++i)a[i]/=n;
    }		
}
// c=a*b
void multiply(vector<int>&a,vector<int>&b,vector<int>&c){
	 vector<base> A(all(a)),B(all(b));
	 int n=1;
	 while(n<max(sz(a),sz(b)))n=n<<1;
	 n=n<<1;
	 A.resize(n),B.resize(n);
	 fft(A,false);
	 fft(B,false);
	 for(int i=0;i<n;i++){
	     A[i]=A[i]*B[i];
	 }
	 fft(A,true);
	 c.resize(n);
	 for(int i=0;i<n;i++)c[i]=(int)(A[i].real()+0.5); 
	 while(sz(c)>k+1)c.pop_back();	
	 for(int i=0;i<sz(c);i++)c[i]%=1009;
}
int solve(){
 cin>>n>>m>>k;
 multiset<pair<int,vector<int>>>st;
 map<int,int>mp;
 for(int i=1;i<=n;i++){
 	int t;cin>>t;
 	mp[t]++;
 }
 for(auto i:mp){
    vector<int>v(i.y+1,1);
    st.insert({i.y+1,v});
 }
 while(st.size()>1){
 	  auto itr=st.begin();
 	  vector<int>p1=itr->y;
 	  ++itr;
 	  vector<int>p2=itr->y;
 	  //for(int i=0;i<sz(p1);i++)cout<<p1[i]<<" ";cout<<endl;
      //for(int i=0;i<sz(p2);i++)cout<<p2[i]<<" ";cout<<endl;
      st.erase(st.begin());
 	  st.erase(st.begin());
      vector<int>c;
      multiply(p1,p2,c);
     // for(int i=0;i<sz(c);i++)cout<<c[i]<<" ";cout<<endl;
      st.insert({sz(c),c}); 
 }
 vector<int>v=st.begin()->y;
 cout<<v[k]%1009<<endl;
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
    while(t--){
        solve();
    }
    return 0;
}