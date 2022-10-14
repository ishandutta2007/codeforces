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


const int th=300;
const int N=1e5+5;

vector<pii>g[N];

int solve(){
 	int n,m,q;cin>>n>>m>>q;
 	vector<int>a(n+1);
 	rep(i,1,n+1){
 		cin>>a[i];
 	}
 	vector<vector<int>>s(m+1);
 	vector<int>ans(m+1);
 	rep(i,1,m+1){
 		int k;cin>>k;
 		s[i].resize(k);
 		rep(j,0,k){
 			cin>>s[i][j];
 			ans[i]+=a[s[i][j]];
 		}
 	}
 	vector<int>cnt(n+1);
 	rep(i,1,m+1){
 		if(sz(s[i])>th){
 			for(auto j:s[i])cnt[j]++;	
 			rep(j,1,m+1){
 				if(sz(s[j])>th)continue;
 				int c=0;
 				for(auto j:s[j])c+=cnt[j];
 				if(c)g[j].pb({i,c});	
 			}
 			rep(j,1,m+1){
 				if(j!=i && sz(s[j])>th){
 					int c=0;
 					for(auto j:s[j])c+=cnt[j];
 					if(c)g[i].pb({j,c});
 				}
 			}
 			for(auto j:s[i])cnt[j]--;	
 		}
 	}
 	vector<int>upd(m+1);
 	rep(i,0,q){
 		char c;cin>>c;
 		if(c=='+'){
 			int k,x;cin>>k>>x;
 			if(sz(s[k])<=th){
 				// for light 
 				for(auto j:s[k])a[j]+=x;
 				// for heavy 	
 				for(auto j:g[k]){
 					ans[j.x]+=x*j.y;
 				}	
 			}
 			else{
 				upd[k]+=x;
 				ans[k]+=x*sz(s[k]);
 			} 			

 		}
 		else{
 			int k;cin>>k;
 			if(sz(s[k])<=th){
 				int res=0;
 				for(auto j:s[k])res+=a[j];
 				for(auto j:g[k]){
 					res+=upd[j.x]*j.y;
 				}	
 				cout<<res<<endl;
 			}
 			else{
 				int res=ans[k];
 				for(auto j:g[k]){
 					res+=upd[j.x]*j.y;
 				}
 				cout<<res<<endl;
 			}
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