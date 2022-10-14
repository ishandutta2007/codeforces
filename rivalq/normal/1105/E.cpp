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


const int N=20;

int dp[1<<N];
int f[1<<N];


int solve(){
 		int n,m;cin>>n>>m;
 		int msk=0;
 		vector<int>co(m);
 		int cnt=0;
 		map<string,int>id;
 		rep(i,1,n+1){
 			int t;cin>>t;
 			if(t==1){
 				if(msk==0)continue;
 				for(int j=0;j<m;j++){
 					if((1LL<<j)&msk){
 						co[j]|=(msk);
 					}
 				}
 				msk=0;
 			}
 			else{
 				string s;cin>>s;
 				if(!id.count(s)){
 					id[s]=cnt++;
 				}
 				msk|=(1LL<<id[s]);
 			}
 		}
 		for(int j=0;j<m;j++){
 				if((1LL<<j)&msk){
 					co[j]|=(msk);
 				}
 		}
 		int z=m/2;
 		for(int mask=0;mask<(1LL<<z);mask++){
 			int can_add=(1LL<<z)-1;
 			for(int j=0;j<z;j++){
 				if((1LL<<j)&mask){
 					int t=co[j]&(can_add);
 					can_add^=t;
 				}
 			}
 			for(int j=0;j<z;j++){
 				if((1LL<<j)&can_add){
 					maxs(dp[mask^(1LL<<j)],dp[mask]+1);
 				}
 			}
 		}
 		int ans=0;
 		for(int i=0;i<z;i++){
 			for(int mask=0;mask<(1LL<<z);mask++){
 				if((1LL<<i)&mask){
 					maxs(dp[mask],dp[mask^(1LL<<i)]);
 				}
 			}
 		}
 		int s=z;
 		z=m-z;
 		for(int mask=0;mask<(1LL<<z);mask++){
 				int can_add=((1LL<<z)-1);
 				can_add<<=s;
 				int qu=0;
 				for(int j=0;j<z;j++){
 					if((1LL<<j)&mask){
 						int t=co[j+s]&can_add;
 						can_add^=t;
 						t=co[j+s]&((1LL<<s)-1);
 						qu|=t;
 					}
 				}
 				can_add>>=s;
 				for(int j=0;j<z;j++){
 					if((1LL<<j)&can_add){
 						maxs(f[mask^(1LL<<j)],f[mask]+1);
 					}
 				}
 				qu=((1LL<<s)-1)^qu;
 				maxs(ans,f[mask]+dp[qu]);
 		}
 		cout<<ans<<endl;
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