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
 vector<int>fr(1<<9,0);
 vector<int>dp(1<<9,0);
 map<int,set<pii>>mp;
 for(int i=0;i<n;i++){
 	int k;cin>>k;
 	int mask=0;
 	for(int j=0;j<k;j++){
 		int b;cin>>b;
 		--b;
 		mask|=(1<<b);
 	}
 	fr[mask]++;
 } 
 for(int i=0;i<(1<<9);i++){
    for(int s=i;s;s=(s-1)&i){
       dp[i]+=fr[s];
    }
 }
 for(int i=0;i<m;i++){
 	int c,r;cin>>c>>r;
 	int mask=0;
 	for(int j=0;j<r;j++){
 		int b;cin>>b;
 		--b;
 		mask|=(1<<b);
 	}
 	mp[mask].insert({c,i+1});
 }
 pii ans={-1,-1};
 int mi=1e18;
 int mx=0;
 for(int i=0;i<(1<<9);i++){
 	if(mp[i].empty())continue;
 	for(int j=0;j<(1<<9);j++){
 		if(mp[j].empty())continue;
 		if(i==j){
 			if(mp[i].size()<2)continue;
            int t=dp[i];
            auto itr=mp[i].begin();
            int cost=itr->x;
            int idx1=itr->y;
            itr++;
            int idx2=itr->y;
            cost+=itr->x;
            if(t>mx){
            	mx=t;
                mi=cost;
                ans={idx1,idx2};
            } 
            else if(t==mx){
            	if(mi>cost){
            		mi=cost;
            		ans={idx1,idx2};
            	}
            }
 		}
 		else{
 			int mask=i|j;
 			int t=dp[mask];
 			int cost=mp[i].begin()->x+mp[j].begin()->x;
 			int idx1=mp[i].begin()->y;
 			int idx2=mp[j].begin()->y;
 			if(t>mx){
            	mx=t;
                mi=cost;
                ans={idx1,idx2};
            } 
            else if(t==mx){
            	if(mi>cost){
            		mi=cost;
            		ans={idx1,idx2};
            	}
            }
 		}
 	}
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