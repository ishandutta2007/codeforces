#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
//#define int            long long
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


const int B = 475;

const int M = 1e9+5;




int solve(){
 		int n;cin>>n;
 		vector<int>v[n+1];
 		vector<int>b;
 		rep(i,1,n+1){
 			int k;cin>>k;
 			rep(j,0,k){
 				int t;cin>>t;
 				v[i].pb(t);b.pb(t);
 			}
 		}	
 		sort(all(b));
 		map<int,int>key;
 		int m=sz(b);
 		int cur=1;key[b[0]]=1;
 		for(int i=1;i<sz(b);i++){
 			if(b[i]!=b[i-1])cur++;
 			key[b[i]]=cur;
 		}
 		for(int i=1;i<=n;i++){
 			for(int j=0;j<sz(v[i]);j++){
 				v[i][j]=key[v[i][j]];
 			}
 		} 		
 		vector<int>ac(m+1);
 		rep(i,1,n+1){
 			if(sz(v[i])>=B){
 				for(auto j:v[i]){
 					ac[j]=1;
 				}
 				rep(j,1,n+1){
 					if(i==j)continue;
 					int cnt=0;
 					for(auto k:v[j]){
 						if(ac[k]){
 							cnt++;
 							if(cnt==2)break;
 						}
 					}
 					if(cnt>1){
 						cout<<j<<" "<<i<<endl;return 0;
 					}
 				}
 				for(auto j:v[i]){
 					ac[j]=0;
 				}
 			}
 		}
 		vector<int>vec[m+1];
 		rep(i,1,n+1){
 			if(sz(v[i])<B){
 				for(int j=0;j<sz(v[i]);j++){
 					vec[v[i][j]].emplace_back(i);
 				}
 			}
 		}
 		vector<int>t(m+1);
 		rep(i,1,m+1){
 			for(auto j:vec[i]){
 				for(auto k:v[j]){
 					if(k==i)continue;
 					if(t[k]){
 						cout<<t[k]<<" "<<j<<endl;return 0;
 					}
 					t[k]=j;
 				}
 			}
 			for(auto j:vec[i]){
 				for(auto k:v[j]){
 					t[k]=0;
 				}
 			}
 		}
 		cout<<-1<<endl;return 0;
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