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


const int maxn=200005;
int p[maxn];
int sz[maxn];
void clear(int n){
    rep(i,0,n+1)p[i]=i,sz[i]=1;
}
int root(int x){
   while(x!=p[x]){
       p[x]=p[p[x]];
       x=p[x];
   }
   return x;  
}
void merge(int x,int y){
    int p1=root(x);
    int p2=root(y);
    if(p1==p2)return;
    if(sz[p1]>=sz[p2]){
        p[p2]=p1;
        sz[p1]+=sz[p2];
    }
    else{
        p[p1]=p2;
        sz[p2]+=sz[p1];
    }
}


int solve(){
 		int n;cin>>n;
 		vector<vector<int>>a(n+1,vector<int>(n+1));
 		vector<vector<int>>b=a;
 		clear(2*n+1);
 		for(int i=1;i<=n;i++){
 			for(int j=1;j<=n;j++){
 				char c;cin>>c;
 				a[i][j]=c-'0';
 			}
 		}
 		vector<int>g[2*n+1];
 		bool f=0;
 		for(int i=1;i<=n;i++){
 			for(int j=1;j<=n;j++){
 				char c;cin>>c;
 				b[i][j]=c-'0';
 				if((b[i][j]^a[i][j])>1){
 					f=1;
 				}
 				if(b[i][j]==a[i][j])merge(i,j+n);
 			}
 		}
 		if(f){
 			cout<<"NO"<<endl;return 0;
 		}
 		for(int i=1;i<=n;i++){
 			for(int j=1;j<=n;j++){
 				if(a[i][j]!=b[i][j]){
 					g[root(i)].push_back(root(j+n));
 					g[root(j+n)].push_back(root(i));
 				}
 			}
 		}
 		vector<int>c(2*n+1);
 		vector<int>vis(2*n+1);
 		queue<int>q;
 		for(int i=1;i<=2*n;i++){
 			if(!vis[i]){
 				q.push(i);
 				vis[i]=1;
 				while(!q.empty()){
 					int v=q.front();q.pop();
 					for(auto j:g[v]){
 						if(vis[j]){
 							if(c[j]==c[v]){
 								cout<<"NO"<<endl;return 0;
 							}
 						}
 						else{
 							q.push(j);vis[j]=1;
 							c[j]=c[v]^1;
 						}
 					}
 				}
 			}
 		}
 		cout<<"YES"<<endl;
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