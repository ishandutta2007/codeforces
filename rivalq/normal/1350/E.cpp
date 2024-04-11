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
 int n,m,t;cin>>n>>m>>t;
 vector<vector<char>>mat(n+1,vector<char>(m+1));
 rep(i,1,n+1){
 	rep(j,1,m+1)cin>>mat[i][j];
 }
 vector<vector<int>>lvl(n+1,vector<int>(m+1,1e18+1));
 vector<vector<int>>vis(n+1,vector<int>(m+1,0));

 queue<pii>q;
 for(int i=1;i<=n;i++){
 	for(int j=1;j<=m;j++){
 		bool f=0;
 		if(i>1 && mat[i-1][j]==mat[i][j])f=1;
 		if(i<n && mat[i+1][j]==mat[i][j])f=1;
 		if(j>1 && mat[i][j-1]==mat[i][j])f=1;
 		if(j<m && mat[i][j+1]==mat[i][j])f=1;
        if(f)q.push({i,j}),lvl[i][j]=0,vis[i][j]=1;
 	}
 }
 while(!q.empty()){
     pii p=q.front();
     q.pop();
     vis[p.x][p.y]=1;
     if(p.x>1 && vis[p.x-1][p.y]==0){
     	lvl[p.x-1][p.y]=lvl[p.x][p.y]+1;
     	vis[p.x-1][p.y]=1;
     	q.push({p.x-1,p.y});
     }
     if(p.y>1 && vis[p.x][p.y-1]==0){
     	lvl[p.x][p.y-1]=lvl[p.x][p.y]+1;
     	vis[p.x][p.y-1]=1;
     	q.push({p.x,p.y-1});
     }
     if(p.x<n && vis[p.x+1][p.y]==0){
     	lvl[p.x+1][p.y]=lvl[p.x][p.y]+1;
     	vis[p.x+1][p.y]=1;
     	q.push({p.x+1,p.y});
     }
     if(p.y<m && vis[p.x][p.y+1]==0){
     	lvl[p.x][p.y+1]=lvl[p.x][p.y]+1;
     	vis[p.x][p.y+1]=1;
     	q.push({p.x,p.y+1});
     }
 }
 rep3(t){
 	int x,y,p;cin>>x>>y>>p;
 	if(lvl[x][y]>=p){
 		cout<<mat[x][y]<<endl;
 	}
 	else{
 		int d=p-lvl[x][y];
 		if(d%2)cout<<!(mat[x][y]-48)<<endl;
 		else cout<<mat[x][y]<<endl;
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