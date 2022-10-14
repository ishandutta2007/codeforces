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
 	vector<pii>a(n+1),b(n+1);
 	set<int>s;
 	rep(i,1,n+1){
 		cin>>a[i];
 		cin>>b[i];
 		s.insert(a[i].x);
 		s.insert(a[i].y);
 		s.insert(b[i].x);
 		s.insert(b[i].y);
 	}
 	map<int,int>mp;int cnt=0;
 	for(auto i:s){
 		mp[i]=++cnt;
 	}
 	rep(i,1,n+1){
 		a[i].x=mp[a[i].x];
 		a[i].y=mp[a[i].y];
 		b[i].x=mp[b[i].x];
 		b[i].y=mp[b[i].y];
 	}
 	auto func=[&](){
 		vector<pii>in[4*n+1],out[4*n+1];
 		rep(i,1,n+1){
 			in[a[i].x].pb(b[i]);
 			out[a[i].y].pb(b[i]);
 		}
 		map<int,int>start,end;
 		rep(i,1,4*n+1){
 			for(auto j:in[i]){
 				int l=j.x,r=j.y;
 				if(!start.empty()){
 					auto itr=start.rbegin();
 					if(itr->x>r)return 0;
 				}
 				if(!end.empty()){
 					auto itr=end.begin();
 					if(itr->x<l)return 0;
 				}
 				start[l]++;
 				end[r]++;
 			}
 			for(auto j:out[i]){
 				int l=j.x,r=j.y;
 				start[l]--;
 				end[r]--;
 				if(start[l]==0)start.erase(l);
 				if(end[r]==0)end.erase(r);
 			}
 		}
 		return 1;
 	};
 	bool f=func();
 	swap(a,b);
 	f&=func();
 	if(f)cout<<"YES"<<endl;
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