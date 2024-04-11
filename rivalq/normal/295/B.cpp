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


int solve(){
 	int n;cin>>n;
 	vector<vector<int>>a(n+1,vector<int>(n+1)),dp(n+1,vector<int>(n+1,1e8));
 	rep(i,1,n+1){
 		rep(j,1,n+1){
 			cin>>dp[i][j];
 		}
 	}
 	vector<int>v(n);
 	rep3(n)cin>>v[i];reverse(all(v));
 	vector<int>st;
 	vector<bool>u(n+1,0);
 	vector<ll>ans;
 	for(auto i:v){
 		ll c=0;
                u[i]=1;
                st.pb(i);

                for(int x=1;x<=n;x++){
                	for(int y=1;y<=n;y++){
                             mins(dp[x][y],dp[x][i]+dp[i][y]);
                	}
                }
                for(int x:st){
                	for(int y:st){
                		c+=dp[x][y];
                	}
                }
                ans.pb(c);
 	}
 	while(!ans.empty()){
 		cout<<ans.back()<<" ";
 		ans.pop_back();
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