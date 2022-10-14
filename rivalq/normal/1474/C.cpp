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


int solve(){
 	int n;cin>>n;
 	vector<int>a(2*n+1);
 	map<int,int>mp;
 	rep(i,1,2*n+1){
 		cin>>a[i];
 		mp[a[i]]++;
 	}
 	vector<pii>ans;
 	auto solve=[&](int x,int y){
 		map<int,int>t=mp;
 		t[x]--;t[y]--;
 		if(t[x]==0)t.erase(x);
 		if(t[y]==0)t.erase(y);
 		ans.clear();
 		ans.push_back({x,y});
 		int s=max(x,y);
 		while(!t.empty()){
 			auto itr=t.rbegin();
 			int need=s-itr->x;
 			s=itr->x;
 			if(t[need]==0){
 				return 0;
 			}
 			itr->y--;
 			ans.push_back({itr->x,need});
 			if(itr->y==0)t.erase(itr->x);
 			t[need]--;
 			if(t[need]==0)t.erase(need);
 		}
 		return 1;
 	};
 	sort(a.begin()+1,a.end());
 	for(int i=1;i<2*n;i++){
 		if(solve(a[i],a[2*n])){
 			cout<<"YES"<<endl;
 			cout<<a[i]+a[2*n]<<endl;
 			for(auto i:ans)cout<<i<<endl;return 0;
 		}
 	}	
 	cout<<"NO"<<endl;
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