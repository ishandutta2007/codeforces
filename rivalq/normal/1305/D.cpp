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

const int N=1005;

set<int>g[N];
vector<int>st;
void dfs(int u,int p,int l=0){
	if(g[u].size()==1){
		st.pb(u);
	}
	for(auto i:g[u]){
		if(i!=p){
			dfs(i,u,l+1);
		}
	}
	
}

int solve(){
 	int n;cin>>n;
 	rep3(n-1){
 		int a,b;cin>>a>>b;
 		g[a].insert(b);
 		g[b].insert(a);
 	}
 	set<int>s;
 	rep(i,1,n+1)s.insert(i);
 	while(1){
 	     st.clear();
             if(sz(s)==1){
             		cout<<"! "<<*s.begin()<<endl;cout<<flush;exit(0);
             }
             int r=*s.begin();
             dfs(r,r,0);
             int v=st.back();
             st.pop_back();
             int u=st.back();
             cout<<"? "<<v<<" "<<u<<endl;cout<<flush; 
             int x;cin>>x;
             if(x==v || x==u){
             	cout<<"! "<<x<<endl;cout<<flush;exit(0);
             }
             s.erase(v);
             s.erase(u);
             for(auto i:g[v]){
             		g[i].erase(v);
             }
             for(auto i:g[u]){
             		g[i].erase(u);
             }
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