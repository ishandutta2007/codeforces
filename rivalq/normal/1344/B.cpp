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
const int maxn=1000005;
int p[maxn];
int sz[maxn];
void clear(int n=maxn){
    rep(i,0,maxn)p[i]=i,sz[i]=1;
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
char mat[1001][1001];
int get(int i,int j,int n,int m){
	return m*(i-1)+j;
}
int solve(){
 int n,m;cin>>n>>m;
 rep(i,1,n+1){
 	rep(j,1,m+1)cin>>mat[i][j]; 
 }
 vector<int>rows,col;
 for(int i=1;i<=n;i++){
 	bool f=1;
 	for(int j=1;j<=m;j++){
       if(mat[i][j]=='#')f=0;
 	}
 	int j=1;
 	int cnt=0;
 	while(j<=m){
 		if(mat[i][j]=='.')j++;
 		else{
 			while(j<=m && mat[i][j]=='#')j++;
 			cnt++;
 		}
 	}
 	if(cnt>1){
 		cout<<-1<<endl;exit(0);
 	}
 	if(f)rows.pb(i); 
 }
 for(int j=1;j<=m;j++){
 	bool f=1;
 	for(int i=1;i<=n;i++){
 		if(mat[i][j]=='#')f=0;
 	}
 	int i=1;
 	int cnt=0;
 	while(i<=n){
 		if(mat[i][j]=='.')i++;
 		else{
 			while(i<=n && mat[i][j]=='#')i++;
 			cnt++;
 		}
 	}
 	if(cnt>1){
 		cout<<-1<<endl;exit(0);
 	}
 	if(f)col.pb(j);
 }
 if(min(sz(rows),sz(col))==0 && sz(rows)!=sz(col)){
 	cout<<-1<<endl;exit(0);
 }
 clear();
 for(int i=1;i<=n;i++){
 	for(int j=1;j<=m;j++){
       if(mat[i][j]=='#'){
       	  if(i>1 && mat[i-1][j]=='#')merge(get(i-1,j,n,m),get(i,j,n,m));
       	  if(j>1 && mat[i][j-1]=='#')merge(get(i,j,n,m),get(i,j-1,n,m));
       	  if(i<n && mat[i+1][j]=='#')merge(get(i+1,j,n,m),get(i,j,n,m));
       	  if(j<m && mat[i][j+1]=='#')merge(get(i,j,n,m),get(i,j+1,n,m));
       }  
 	}
 }
 set<int>s;
 for(int i=1;i<=n;i++){
 	for(int j=1;j<=m;j++){
 		if(mat[i][j]=='#'){
 			s.insert(root(get(i,j,n,m)));
 		}
 	}
 }
 cout<<sz(s)<<endl;	
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