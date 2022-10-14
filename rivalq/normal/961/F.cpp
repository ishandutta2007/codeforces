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
typedef unsigned long long ull;
const int maxn=1000005;
int dp1[maxn];
int dp2[maxn];
struct HASH{
   int *hash1;
   int *hash2;
   int base1,base2; 
   int  hell1,hell2;
   int gen_base(const int before, const int after) {
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 mt_rand(seed ^ ull(new ull));
    int base = std::uniform_int_distribution<int>(before+1, after)(mt_rand);
    return base % 2 == 0 ? base-1 : base;
   }
    HASH(int n){
       hash1=new int[n+10];
       hash2=new int[n+10];
       base1=gen_base(2000,4000);
       base2=gen_base(3000,6000);
       hell1=hell;
       hell2=hell+gen_base(hell,2147483647); 
       hash1[0]=hash2[0]=1;
       rep(i,1,n+10) hash1[i]=hash1[i-1]*base1%hell1;
       rep(i,1,n+10) hash2[i]=hash2[i-1]*base2%hell2;
   }
   void generate(string &s){
   	   dp1[1]=s[0];
   	   dp2[1]=s[0];
   	   for(int i=1;i<s.length();i++){
          dp1[i+1]=(dp1[i]+s[i]*hash1[i])%hell1;
          dp2[i+1]=(dp2[i]+s[i]*hash2[i])%hell2; 
   	   }
   }
   bool ch(int i,int j,int len){
        int pre1=(dp1[i+len]-dp1[i]+hell)*hash1[j]%hell;
        int pre2=(dp1[j+len]-dp1[j]+hell)*hash1[i]%hell; 
        int pre3=(dp2[i+len]-dp2[i]+hell2)*hash2[j]%hell2;
        int pre4=(dp2[j+len]-dp2[j]+hell2)*hash2[i]%hell2; 
        return pre1==pre2;
   }

   
}h(maxn);
int ans[maxn];
int res[maxn];
int solve(){
 int n;cin>>n;
 string s;cin>>s;
 h.generate(s);
 for(int i=0;i<n/2;i++){
 	int center1=i;
 	int center2=n-i-1;
 	if(s[center1]!=s[center2]){
 		ans[i]=-1;
 		continue;
 	}
 	int l=0;
 	int u=i;
    while(l<=u){
    	int mid=(l+u)/2;
        if(h.ch(center1-mid,center2-mid,2*mid+1))ans[i]=mid,l=mid+1;
        else u=mid-1;
    }
 }
 for(int i=0;i<n/2;i++){
 	if(ans[i]<0)continue;
 	res[i-ans[i]]=max(res[i-ans[i]],2*ans[i]+1);
 }
 for(int i=1;i<n/2;i++)res[i]=max(res[i],res[i-1]-2);
 for(int i=0;i<(n+1)/2;i++){
 	if(res[i]==0)cout<<-1<<" ";
 	else cout<<res[i]<<" ";
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