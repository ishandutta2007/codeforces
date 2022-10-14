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
	 int n;cin>>n;
	 if(n&1){
	 	cout<<-1<<endl;return 0;
	 }
	 vector<char>a(n+1);
	 vector<char>b(n+1);
	 for(int i=1;i<=n;i++){
             if(i%4==1 || i%4==2)a[i]='w',b[i]='b';
             else a[i]='b',b[i]='w';
	 }
	 auto p=[&](int x){
	 	if(x==0){
	 		for(int i=1;i<=n;i++)cout<<a[i];
	 	}
	        else {
	        	for(int i=1;i<=n;i++)cout<<b[i];
	        }
	        cout<<endl;
	 };
	 for(int i=1;i<=n;i+=2){
	     if(i%4==1 || i%4==2){
	     	 for(int k=0;k<=1;k++){
	     	 	for(int z=1;z<=n;z++)p(z%2);
	     	 	cout<<endl;	
	     	 }
	     }
	     else{
	     	for(int k=0;k<=1;k++){
	     	 	for(int z=1;z<=n;z++)p(1-z%2);
	     	 	cout<<endl;	
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