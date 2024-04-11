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


const int N = 2e5;
vector<int>g1[N],g2[N],g3[N];

int solve(){
 		int n1,n2,n3,n4;cin>>n1>>n2>>n3>>n4;
 		vector<int>a(n1+1),b(n2+1),c(n3+1),d(n4+1);
 		rep(i,1,n1+1){
 			cin>>a[i];
 		}
 		rep(i,1,n2+1){
 			cin>>b[i];
 		}
 		rep(i,1,n3+1){
 			cin>>c[i];
 		}
 		rep(i,1,n4+1){
 			cin>>d[i];
 		}
 		int m;cin>>m;
 		rep(i,0,m){
 			int a,b;cin>>a>>b;
 			g1[a].push_back(b);
 		}
 		cin>>m;
 		rep(i,0,m){
 			int a,b;cin>>a>>b;
 			g2[a].push_back(b);
 		}
 		cin>>m;
 		rep(i,0,m){
 			int a,b;cin>>a>>b;
 			g3[a].push_back(b);
 		}
 		vector<int>res(n3+1,1e12);
 		set<pii>st;
 		rep(i,1,n4+1){
 			st.insert({d[i],i});
 		}
 		rep(i,1,n3+1){
 			for(auto j:g3[i]){
 				st.erase({d[j],j});
 			}
 			if(!st.empty()){
 				res[i]=c[i]+st.begin()->x;
 			}
 			for(auto j:g3[i]){
 				st.insert({d[j],j});
 			}
 		}
 		st.clear();
 		rep(i,1,n3+1){
 			st.insert({res[i],i});
 		}
 		vector<int>res2(n2+1,1e12);
 		rep(i,1,n2+1){
 			for(auto j:g2[i]){
 				st.erase({res[j],j});
 			}
 			if(!st.empty()){
 				res2[i]=b[i]+st.begin()->x;
 			}
 			for(auto j:g2[i]){
 				st.insert({res[j],j});
 			}
 		}
 		st.clear();
 		rep(i,1,n2+1){
 			st.insert({res2[i],i});
 		}
 		int ans=1e12;
 		rep(i,1,n1+1){
 			for(auto j:g1[i]){
 				st.erase({res2[j],j});
 			}
 			if(!st.empty()){
 				mins(ans,a[i]+st.begin()->x);
 			}
 			for(auto j:g1[i]){
 				st.insert({res2[j],j});
 			}
 		}
 		if(ans==1e12){
 			cout<<-1<<endl;
 		}
 		else{
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