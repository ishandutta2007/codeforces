#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
#define ook order_of_key
#define fbo find_by_order

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
 		vector<int>v(3);
 		cin>>v[0]>>v[1]>>v[2];
 		sort(all(v));
 		Tree<pii>tr;
 		rep(i,1,n+1){
 			int t ;cin>>t;
 			if(t>v[0]+v[1]+v[2]){
 				cout<<-1<<endl;return 0;
 			}
 			tr.insert({t,i});
 		}
 		int ans=0;
 		auto rem = [&](int a){
 			if(!tr.empty() && tr.begin()->x<=a){
 				auto itr=tr.upper_bound({a,n+1});
 				itr--;
 				tr.erase(itr);
 				return 1;
 			}
 			return 0;
 		};
 		while(!tr.empty() && tr.rbegin()->x>v[1]+v[2]){
 			auto val=*tr.rbegin();
 			tr.erase(val);ans++;
 		}
 		while(!tr.empty() && tr.rbegin()->x>v[0]+v[2]){
 			auto val=*tr.rbegin();
 			tr.erase(val);ans++;rem(v[0]);
 		}
 		while(!tr.empty() && tr.rbegin()->x>max(v[2],v[0]+v[1])){
 			auto val=*tr.rbegin();
 			tr.erase(val);ans++;rem(v[1]);
 		}
 		auto f=[&](){
 			if(tr.empty())return 0LL;
 			int f1=tr.ook({v[0]+v[1],n+1});
 			int f2=tr.ook({v[2],n+1});
 			if(f2>f1)swap(f1,f2);
			if(f1>=2*f2)return f1-f2;
			int val=max(0LL,(sz(tr)-2*(f1-f2)));
			val=val/2+val%2;
			return val+f1-f2;
 		};
 		int z=ans;
 		ans=hell;
 		int cnt=0;
 		mins(ans,z+f());
 		while(!tr.empty()){
 			bool ff=rem(v[0])|rem(v[1])|rem(v[2]);
 			if(ff==0){
 				mins(ans,z+f()+cnt);break;
 			}
 			else{
 				cnt++;
 				mins(ans,z+f()+cnt);
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
//  x   y   z  p q r 
// a+b,b+c,c+a,a,b,c