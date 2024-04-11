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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int N=1e3+5;

unordered_map<bitset<N>,int>st1,st2;
vector<bitset<N>>dp(1<<20);
const int thres=10;
vector<bitset<N>>vec(32);

int solve(){
 	int n,s,d;cin>>n>>s>>d;
 	int m=s/2;
 	
 	rep(i,0,s){
 		int m;cin>>m;
 		rep(j,0,m){
 			int t;cin>>t;
 			vec[i][t]=1;
 		}	
 	}
 	int r=m;
 	st1[dp[0]]=0;
 	for(int i=1;i<(1<<thres);i++){
 		int j=i&(-i);
 		int idx=log2(j);
 		dp[i]=dp[i-j]^vec[idx];
 		int cnt=__builtin_popcount(i);
 		if(st1.count(dp[i]))mins(st1[dp[i]],cnt);
 		else st1[dp[i]]=cnt;
 	}
 	st2[dp[0]]=0;
 	m=s-m;
 	for(int i=1;i<(1<<(30-thres));i++){
 		int j=i&(-i);
 		int idx=log2(j);
 		dp[i]=dp[i-j]^vec[idx+thres];
 		int cnt=__builtin_popcount(i);
 		if(st2.count(dp[i]))mins(st2[dp[i]],cnt);
 		else st2[dp[i]]=cnt;
 	}
 	auto query=[&](bitset<N>&dp){
 		int mi=hell;
 		for(auto i:st1){
 			dp^=i.x;
 			if(st2.count(dp))mins(mi,i.y+st2[dp]);
 			dp^=i.x;
 		}
 		return (mi==hell)?-1:mi;
 	};
 	rep(i,0,d){
 		int t;cin>>t;
 		bitset<N>dp;
 		rep(j,0,t){
 			int x;cin>>x;
 			dp[x]=1;
 		}
 		cout<<query(dp)<<endl;
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