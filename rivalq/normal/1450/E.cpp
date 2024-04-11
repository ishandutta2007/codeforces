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
 	int n,m;cin>>n>>m;
 	vector<vector<int>>a(n+1,vector<int>(n+1,hell));
 	rep(i,1,n+1){
 		a[i][i]=0;
 	}
 	vector<pii>edges;
 	rep(i,0,m){
 		int u,v,c;cin>>u>>v>>c;
 		edges.pb({u,v});
 		if(c==1){
 			a[u][v]=1;
 			a[v][u]=-1;
 		}
 		else{
 			a[u][v]=1;
 			a[v][u]=1;
 		}
 	}
 	rep(k,1,n+1){
 		rep(i,1,n+1){
 			rep(j,1,n+1){
 				if(a[i][k]!=hell && a[k][j]!=hell && a[i][k]+a[k][j]<a[i][j]){
 						a[i][j]=a[i][k]+a[k][j];
 				}
 			}
 		}
 	}
 	pii  ans = {-1,-1};
 	rep(i,1,n+1){
 		if(a[i][i]<0){
 			cout<<"NO"<<endl;return 0;
 		}
 		rep(j,1,n+1){
 			maxs(ans,make_pair(a[i][j],i));
 		}
 	}
 	for(auto i:edges){
 		if(a[ans.y][i.x]==a[ans.y][i.y]){
 			cout<<"NO"<<endl;return 0;
 		}
 	}
 	cout<<"YES"<<endl;
 	cout<<ans.x<<endl;
 	rep(i,1,n+1){
 		cout<<a[ans.y][i]<<" ";
 	}cout<<endl;
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