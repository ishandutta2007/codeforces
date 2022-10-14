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


int solve(){
 	int n;cin>>n;
 	vector<int>g[n+1];
 	int r;
 	rep(i,1,n+1){
 		int p;cin>>p;
 		if(p)g[p].pb(i); 
 		if(!p)r=i;
 	}
 	vector<int>dp(n+1),h(n+1);
 	vector<int>vec;
 	function<void(int)>dfs=[&](int u){
 		int d=0;
 		if(u!=r)d++;
 		for(auto i:g[u]){
 			h[i]=h[u]+1;
 			dfs(i);
 			if(dp[i]==0)d++;
 		}
 		if(d%2==0){
 			vec.pb(u);
 			dp[u]=1;
 		}
 		else dp[u]=0;
 	};
 	dfs(r);
 	if(dp[r]){
 		cout<<"YES"<<endl;
 		vector<pii>p;
 		rep(i,1,n+1){
 			if(dp[i]==0)p.pb({h[i],i});
 		}
 		sort(p.begin(),p.end());
 		for(auto i:vec)cout<<i<<endl;
 		for(auto i:p)cout<<i.y<<endl;	
 	}
 	else{
 		cout<<"NO"<<endl;
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