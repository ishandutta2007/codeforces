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
int dp[1001][1001][11][11];
int a[1001][1001];
int b[1001][1001];
struct sparse{
      int n,m;
      vector<int>Log;
      sparse (int szn,int szm){
             n=szn;
             m=szm;
             Log.resize(max(n,m)+1,0);
             for(int i=1;i<=max(n,m);i++)Log[i]=log2(i);
             for(int i=1;i<=n;i++){
             	for(int j=1;j<=m;j++){
             		dp[i][j][0][0]=a[i][j];
             	}
             }
             for(int i=1;i<=n;i++){
             	for(int k=1;k<11;k++){
             		for(int j=1;j+(1<<(k-1))<=m;j++){
             			dp[i][j][0][k]=max(dp[i][j][0][k-1],dp[i][j+(1<<(k-1))][0][k-1]);
             		}
             	}
             }
             for(int x=1;x<11;x++){
             	for(int y=0;y<11;y++){
             		for(int i=1;i+(1<<(x-1))<=n;i++){
             			for(int j=1;j<=m;j++){
                           dp[i][j][x][y]=max(dp[i][j][x-1][y],dp[i+(1<<(x-1))][j][x-1][y]);
             			}
             		}
             	}
             }
          
      }
      int query(int x1,int x2,int y1,int y2){
      	  int l1=Log[x2-x1+1];
      	  int l2=Log[y2-y1+1];
          if(x1+(1<<l1)-1>x2){
          	 cout<<x1<<x2<<endl;
          	 return 0;
          }
          if(y1+(1<<l2)-1>y2){
          	 cout<<y1<<y2<<endl;return 0;
          }
      	  int ans=dp[x1][y1][l1][l2];
      	  maxs(ans,dp[x2-(1<<l1)+1][y2-(1<<l2)+1][l1][l2]);
      	  maxs(ans,dp[x2-(1<<l1)+1][y1][l1][l2]);
      	  maxs(ans,dp[x1][y2-(1<<l2)+1][l1][l2]);
      	  return ans;
      }  
};
int solve(){
 int n,m;cin>>n>>m;
 rep(i,1,n+1){
 	rep(j,1,m+1){
 		cin>>b[i][j];
 		if(b[i][j])a[i][j]=min({a[i-1][j-1],a[i-1][j],a[i][j-1]})+1;
 	}
 }
 sparse sp(n,m);
 int t;cin>>t;
 while(t--){
 	int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
 	int l=1;
 	int r=min(x2-x1,y2-y1)+1;
 	int ans=0;
 	while(l<=r){
 		int m=(l+r)/2;
 		int xnew=x1+m-1;
 		int ynew=y1+m-1;
 		//cout<<"#"<<xnew<<" "<<ynew<<" "<<m<<endl;
 		if(sp.query(xnew,x2,ynew,y2)>=m)ans=m,l=m+1;
 		else r=m-1;
 	}
 	cout<<ans<<endl;
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