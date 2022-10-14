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


int solve(){
 	int n;cin>>n;
 	vector<pii>a(n+1);
 	map<int,vector<pii>>mp;
 	map<int,vector<pii>>q;
 	vector<int>ans(n+1,-1);
 	rep(i,1,n+1){
 		cin>>a[i];
 		mp[a[i].x].push_back({a[i].y,i});
 		mp[a[i].y].push_back({a[i].x,i});
 		q[a[i].x].push_back({a[i].y,i});
 	}
 	auto itr=mp.begin();
 	pii y_min={hell,hell};
 	for(auto i:q){
 		while(itr!=mp.end() && itr->x<i.x){
 			for(auto j:itr->y)mins(y_min,j);
 			itr++;
 		}
 		for(auto j:i.y){
 			if(j.x>y_min.x)ans[j.y]=y_min.y;
 		}
 	}
 	rep(i,1,n+1){
 		cout<<ans[i]<<" ";
 	}cout<<endl;
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