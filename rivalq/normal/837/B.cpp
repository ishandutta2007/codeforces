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
 char a[n+1][m+1];
 rep(i,1,n+1){
 	rep(j,1,m+1)cin>>a[i][j];
 }
 bool f1=0;
 if(n%3==0){
 	set<char>s1,s2,s3;
 	for(int i=1;i<=n/3;i++){
 		for(int j=1;j<=m;j++)s1.insert(a[i][j]);
 	}
    for(int i=n/3+1;i<=2*n/3;i++){
 		for(int j=1;j<=m;j++)s2.insert(a[i][j]);
 	}
    for(int i=2*n/3+1;i<=n;i++){
 		for(int j=1;j<=m;j++)s3.insert(a[i][j]);
 	}
    if(sz(s1)==1 && sz(s2)==1 &&sz(s3)==1){
    	char c1=*s1.begin();
    	char c2=*s2.begin();
    	char c3=*s3.begin();
    	if(c1!=c2 && c2!=c3 && c3!=c1)f1=1;
    }
 }
 if(m%3==0){
    set<char>s1,s2,s3;
 	for(int i=1;i<=n;i++){
 		for(int j=1;j<=m/3;j++)s1.insert(a[i][j]);
 	}
    for(int i=1;i<=n;i++){
 		for(int j=1+m/3;j<=2*m/3;j++)s2.insert(a[i][j]);
 	}
    for(int i=1;i<=n;i++){
 		for(int j=1+2*m/3;j<=m;j++)s3.insert(a[i][j]);
 	}
    if(sz(s1)==1 && sz(s2)==1 &&sz(s3)==1){
    	char c1=*s1.begin();
    	char c2=*s2.begin();
    	char c3=*s3.begin();
    	if(c1!=c2 && c2!=c3 && c3!=c1)f1=1;
    }

 }
 if(f1)cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
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