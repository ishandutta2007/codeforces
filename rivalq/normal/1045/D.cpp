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
 	double ans = 0;
 	vector<int>g[n+1];
 	vector<double>p(n+1);
 	vector<double>s(n+1);
 	rep(i,1,n+1){
 		cin>>p[i];p[i]=1-p[i];
 	}
 	rep(i,0,n-1){
 		int a,b;cin>>a>>b;a++,b++;
 		g[a].pb(b);g[b].pb(a);
 	}
 	vector<int>par(n+1);
 	function<void(int,int)>dfs=[&](int u,int v){
 		for(auto i:g[u]){
 			if(i!=v){
 				s[u]+=p[i];
 				par[i]=u;
 				dfs(i,u);
 			}
 		}
 	};dfs(1,0);
 	int q;cin>>q;
	rep(i,1,n+1){
		ans+=p[i]-p[i]*s[i];
	}	
 	rep(i,0,q){
 		int u;double val;
 		cin>>u>>val;u++;val=1-val;
 		ans-=p[u]-p[u]*s[u];
 		ans+=val-val*s[u];
 		int j = par[u];
 		ans-=-p[j]*s[j];s[j]+=val-p[u];p[u]=val;
 		ans+=-p[j]*s[j];
 		cout<<fixed<<setprecision(10)<<ans<<endl;
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