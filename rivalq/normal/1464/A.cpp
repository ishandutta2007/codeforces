#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}

const int N=1e5+5;

int x[N],y[N];

set<pii>st,used;
int l=0;

bool dfs(pii u,pii p){
	used.insert(u);
	st.insert(u);l++;
	int i=u.x,j=u.y;
	if(y[i]){
		pii v={y[i],i};
		if(v!=p){
			if(st.count(v)){
				return 0;
			}
			else{
				bool f=dfs(v,u);
				if(f==0)return 0;
			}
		}
	}
	if(x[j]){
		pii v={j,x[j]};
		if(v!=p){
			if(st.count(v)){
				return 0;
			}
			else{
				bool f=dfs(v,u);
				if(f==0)return 0;
			}
		}
	}
	st.erase(u);
	return 1;
}

int solve(){
 		int n,m;cin>>n>>m;
 		rep(i,1,n+1){
 			x[i]=y[i]=0;
 		}
 		st.clear();
 		used.clear();
 		vector<pii>vec;
 		rep(i,1,m+1){
 			int a,b;cin>>a>>b;
 			if(a!=b){
 				x[a]=b;
 				y[b]=a;
 				vec.pb({a,b});
 			}
 		}	
 		int res=0;
 		for(auto i:vec){
 			st.clear();l=0;
 			if(used.count(i)==0){
 				bool f=dfs(i,i);
 				res+=(!f)+l;
 			}
 		}cout<<res<<endl;
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
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}