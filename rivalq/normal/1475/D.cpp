// Jai Shree Ram  
  
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


int solve(){
 		int n,m;cin>>n>>m;
 		vector<int> a(n+1);
 		int free=0;
 		rep(i,1,n+1){
 			cin>>a[i];
 			free+=a[i];
 		}
 		vector<int>g[3];
 		g[1].push_back(0);
 		g[2].push_back(0);
 		for(int i=1;i<=n;i++){
 			int b;cin>>b;
 			g[b].push_back(a[i]);
 		}
 		if(free<m){
 			cout<<-1<<endl;return 0;
 		}
 		sort(g[1].begin()+1,g[1].end(),greater<int>());
 		sort(g[2].begin()+1,g[2].end(),greater<int>());
 		for(int i=1;i<sz(g[2]);i++){
 			g[2][i]+=g[2][i-1];
 		}
 		int taken=0;
 		int ans=hell;
 		for(int x=0;x<sz(g[1]);x++){
 			taken+=g[1][x];
 			int rem = m - taken;
 			if(rem<=0){
 				mins(ans,x);break;
 			}
 			else if(rem<=g[2].back()){
 				int j=lower_bound(all(g[2]),rem)-g[2].begin();
 				mins(ans,2*j+x);
 			}
 		}
 		cout<<ans<<endl;

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