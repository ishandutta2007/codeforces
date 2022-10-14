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
 	vector<int>in[2*n+1],out[2*n+1];
 	vector<int>ans(n+1);
 	vector<pii>vec(n+1);
 	Tree<int>tr;
 	rep(i,1,n+1){
 		cin>>vec[i];
 		tr.insert(vec[i].x);tr.insert(vec[i].y);
 	}
 	rep(i,1,n+1){
 		vec[i].x=tr.ook(vec[i].x)+1;
 		vec[i].y=tr.ook(vec[i].y)+1;
 		in[vec[i].x].pb(i);
 		out[vec[i].y].pb(i);
 	}
 	set<int>st;
 	int res=0;
 	int mx=-hell;
 	rep(i,1,2*n+1){
 		if(sz(st)==1){
 			ans[*st.begin()]+=(in[i].size()>0);
 		}
 		if(sz(st)==0){
 			res+=(in[i].size()>0);
 			if(in[i].size()==1){
 				ans[in[i].front()]--;
 			}
 		}
 		for(auto j:in[i]){	
 			st.insert(j);
 		}
 		for(auto j:out[i]){
 			st.erase(j);
 		}

 	}
 	rep(i,1,n+1)maxs(mx,ans[i]);
 	cout<<res+mx<<endl;
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