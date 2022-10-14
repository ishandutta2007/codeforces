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
#define elasped_time   1.0 * clock() / CLOCKS_AER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


int solve(){
 int n,m;cin>>n>>m;
 vector<vector<char>>a(n+1,vector<char>(m+1));
 int cnt=0;
 rep(i,1,n+1){
 	rep(j,1,m+1)cin>>a[i][j],cnt+=(a[i][j]=='A');
 }
 if(!cnt){
 	cout<<"MORTAL"<<endl;return 0;
 }
 if(cnt==n*m){
 	cout<<0<<endl;return 0;
 }
 bool f1=1,f2=1,f3=1,f4=1;
 for(int i=1;i<=n;i++)f3=f3&(a[i][1]=='A'),f4=f4&(a[i][m]=='A');
 for(int i=1;i<=m;i++)f1=f1&(a[1][i]=='A'),f2=f2&(a[n][i]=='A');
 if(f1+f2+f3+f4){
 	cout<<1<<endl;return 0;
 }
 int b=0;
 for(int i=1;i<=n;i++){
 	bool f=1;
 	for(int j=1;j<=m;j++)f=f&(a[i][j]=='A');
 	b+=f;	
 }	
 for(int j=1;j<=m;j++){
 	bool f=1;
 	for(int i=1;i<=n;i++)f=f&(a[i][j]=='A');
 	b+=f;	
 }
 if(a[1][1]=='A' || a[1][m]=='A' || a[n][m]=='A' || a[n][1]=='A' || b){
 	cout<<2<<endl;return 0;
 }
 int c=0;
 for(int i=1;i<=n;i++)c+=(a[i][1]=='A'),c+=(a[i][m]=='A');
 for(int i=1;i<=m;i++)c+=(a[1][i]=='A')	,c+=(a[n][i]=='A');
 if(c){
 	cout<<3<<endl;return 0;
 }
 cout<<4<<endl;
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