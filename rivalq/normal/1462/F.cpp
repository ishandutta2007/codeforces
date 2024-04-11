#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
#define ook order_of_key
#define fbo find_by_order
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


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


int solve(){
 	int n;cin>>n;
 	vector<int>in[2*n+1],out[2*n+1];
 	int c=0,t=0;
 	vector<int>a(n+1);
 	vector<pii>b(n+1);
 	Tree<int>tr;
 	rep(i,1,n+1){
 		cin>>b[i];
 		tr.insert(b[i].x);tr.insert(b[i].y);
 	}
 	rep(i,1,n+1){
 		b[i].x=tr.ook(b[i].x)+1;
 		b[i].y=tr.ook(b[i].y)+1;
 		in[b[i].x].pb(i);
 		out[b[i].y].pb(i);
 	}
 	rep(i,1,2*n+1){
 		for(auto j:in[i]){
 			t++;c++;
 			a[j]=c-t;
 		}
 		for(auto j:out[i]){
 			a[j]+=t;c--;
 		}
 	}
 	int ans=n;
 	rep(i,1,n+1){
 		mins(ans,n-a[i]);
 	}cout<<ans<<endl;
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