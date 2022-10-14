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
 	int n,k;cin>>n>>k;
 	vector<int>v1,v2,v3;
 	rep(i,1,n+1){
 		int t,a,b;cin>>t>>a>>b;
 		if(a && b)v1.pb(t);
 		else if(a)v2.pb(t);
 		else if(b)v3.pb(t);
 	}
 	sort(all(v1),greater<int>());
 	sort(all(v2),greater<int>());
 	sort(all(v3),greater<int>());
 	if(sz(v1)+sz(v3)<k || sz(v1)+sz(v2)<k){
 		cout<<-1<<endl;return 0;
 	}
 	int c1=0,c2=0;
 	int res=0;
 	while(c1<k || c2<k){
 		int mn1=1e18;
 		int mn2=1e18;
 		int mn3=1e18;
 		if(!v1.empty()){
 			mn1=v1.back();
 		}
 		if(!v2.empty()){
 			mn2=v2.back();
 		}
 		if(!v3.empty()){
 			mn3=v3.back();
 		}
 		if(mn1<=mn2 && mn1<=mn3 ){
 			c1++;c2++;
 			res+=mn1;
 			v1.pop_back();
 			continue;
 		}
 		else if(c1<k && c2<k){
 			if(mn1<=mn2+mn3){
 				c1++;c2++;
 				res+=mn1;
 				v1.pop_back();
 			}
 			else {
 				c1++;c2++;
 				res+=mn2+mn3;
 				v2.pop_back();
 				v3.pop_back();
 			}
 			continue;
 		}
 		if(c1>=k){
 			if(mn3<=mn1){
 				c2++;
 				res+=mn3;
 				v3.pop_back();
 			}
 			else{
 				c1++;c2++;
 				res+=mn1;
 				v1.pop_back();
 			}
 			continue;
 		}
 		if(c2>=k){
 			if(mn2<=mn1){
 				c1++;
 				res+=mn2;
 				v2.pop_back();
 			}
 			else{
 				c1++;c2++;
 				res+=mn1;
 				v1.pop_back();
 			}
 		}
 	}
 	cout<<res<<endl;
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