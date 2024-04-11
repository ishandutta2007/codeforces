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
 	vector<int>c(n+1,0);
 	for(int i=1;i<=n;i++)cin>>c[i];
 	vector<bool>pr(1e5+1,0);
        rep(i,1,n+1)pr[c[i]]=1;
        set<int>s[100005];
 	rep3(m){
 		int a,b;cin>>a>>b;
 		if(c[a]!=c[b]){
 		     s[c[a]].insert(c[b]);
 		     s[c[b]].insert(c[a]);	 
 		}
 	}
 	int mx=-1;
 	int j=1;
 	for(int i=1;i<=1e5;i++){
 		if(!pr[i])continue;
 		if(mx<sz(s[i])){
 			mx=sz(s[i]);
                        j=i;
 		}
 	}	
 	cout<<j<<endl;
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