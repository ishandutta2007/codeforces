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
       hell1=998244353;
       hell2=gen_base(hell,2147483647); 
       hash1[0]=hash2[0]=1;
       rep(i,1,n+10) hash1[i]=hash1[i-1]*base1%hell1;
       rep(i,1,n+10) hash2[i]=hash2[i-1]*base2%hell2;
   }
   
}st(1000000);
const int N=3e5+5;
int dp[N];
int solve(){
	int n,m;cin>>n>>m;
 	string s,t;cin>>s>>t;
 	vector<int>first(26,-1);
 	vector<int>h(26,0);
 	int hash_t=0;
 	for(int i=0;i<t.length();i++){
 		if(first[t[i]-97]==-1){
 			first[t[i]-97]=i;
 		}
 		h[t[i]-97]=h[t[i]-97]+st.hash1[i];
 		h[t[i]-97]%=st.hell1;
 		hash_t=hash_t+st.hash1[i]*t[i];
 		hash_t%=st.hell1;
 	}
 	dp[0]=s[0];
 	for(int i=1;i<n;i++){
 		dp[i]=dp[i-1]+s[i]*st.hash1[i];
 		dp[i]%=st.hell1;
 	}
 	vector<int>ans;
 	auto get_hash=[&](int i){
 		int h1=0,h2=0;
 		if(i-1>=0)h1=dp[i-1];
 		h2=dp[i+m-1];
 		return (h2-h1+st.hell1)%st.hell1;
 	};
 	for(int i=0;i+m<=n;i++){
 		set<int>stk;
 		vector<int>change(26,-1);
 		bool f=1;
 		for(int j=0;j<26;j++){
 			if(first[j]==-1)continue;
 			int y=first[j];
 			int x=s[i+y]-97;
 			if(stk.count(x)){
 				f=0;
 				break;
 			}
 			if(change[j]!=-1 && change[j]!=x){
 				f=0;break;
 			}
 			change[j]=x;
 			change[x]=j;
 			stk.insert(x);
 		}
 		if(!f)continue;
 		int t_hash=0;
 		int s_hash=get_hash(i);
 		f=1;
 		for(int j=0;j<26;j++){
 			if(first[j]==-1)continue;
 			int to=change[j];
 			if(change[to]!=j){
 				f=0;
 				break;
 			}
 			t_hash=t_hash+(to+97)*h[j];
 			t_hash%=st.hell1;
 		}
 		t_hash=t_hash*st.hash1[i]%st.hell1;
 		if(t_hash==s_hash && f){
 			ans.pb(i+1);
 		}
 	}
 	cout<<sz(ans)<<endl;
 	for(auto i:ans)cout<<i<<" ";cout<<endl;
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