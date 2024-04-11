#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
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

const int s=3e5;
const int maxn=2e6+5;
int ans[maxn];

const double pi=3.141592653589793238;

// optimized version of  fft(iterative)
#define base         complex<double>
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
 for(int i=0;i<n;i++)c[i]=(int)(A[i].real()+0.5); // this will not work for negative numbers
}



int solve(){
 	int n,x,y;cin>>n>>x>>y;
 	vector<int>a(n+2),b(n+2);
 	vector<int>A(s+1),B(s+1);
 	mem1(ans);
 	rep(i,1,n+2){
 		cin>>a[i];
 		b[i]=s-a[i];
 		A[a[i]]=1;
 		B[b[i]]=1;
 	}
 	vector<int>c;
 	multiply(A,B,c);
 	//cout<<sz(c)<<endl;
 	while(c.back()==0)c.pop_back();
 	for(int i=s+1;i<sz(c);i++){
 		if(c[i]){
 			int p=2*(i-s)+2*y;
 			for(int j=p;j<=1e6;j+=p){
 				maxs(ans[j],p);
 			}
 		}
 	}
 	int q;cin>>q;
 	rep3(q){
 		int t;cin>>t;
 		cout<<ans[t]<<" ";
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
    while(t--){
        solve();
    }
    return 0;
}