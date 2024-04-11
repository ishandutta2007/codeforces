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
struct node{
	int left=0;
	int cnt1=0;
	int lazy=0;
};
node v[20000000];
int d=0;
inline void extend(int id,int tl,int tr){
	if(v[id].left==0){
		  int mid=(tl+tr)/2;
		  v[id].left=++d;
		  int r=++d;
          v[v[id].left].cnt1=0;
          v[r].cnt1=0;
	    }
    }
inline void update(int t ,int l,int r,int val,int tl,int tr){
	 if(l>tr || tl>r)return;
	 if(tl>=l && r>=tr){
	 	v[t].cnt1+=val;
	 	v[t].lazy+=val;
	 	return;
	 }
	 if(v[t].lazy){
	 	if(tl!=tr){
           extend(t,tl,tr);
           int mid=(tl+tr)/2;
           int le=v[t].left;
           int ri=le+1;
           v[le].cnt1+=v[t].lazy;
           v[ri].cnt1+=v[t].lazy;
           v[le].lazy+=v[t].lazy;
           v[ri].lazy+=v[t].lazy;
	 	}
	 	v[t].lazy=0;
	 }
	extend(t,tl,tr);
	int mid=(tl+tr)/2;
    update(v[t].left,l,r,val,tl,(tl+tr)/2);
	update(v[t].left+1,l,r,val,(tl+tr)/2+1,tr);
	v[t].cnt1=min(v[v[t].left].cnt1,v[v[t].left+1].cnt1);
}
int query(int t,int l,int r,int tl,int tr){
	if(l>tr || tl>r)return hell;
	if(v[t].lazy){
	 	if(tl!=tr){
           extend(t,tl,tr);
           int mid=(tl+tr)/2;
           int le=v[t].left;
           int ri=le+1;
           v[le].cnt1+=v[t].lazy;
           v[ri].cnt1+=v[t].lazy;
           v[le].lazy+=v[t].lazy;
           v[ri].lazy+=v[t].lazy;
	 	}
	 	v[t].lazy=0;
	}
	if(l<=tl && tr<=r)return v[t].cnt1;
	int a=query(v[t].left,l,r,tl,(tr+tl)/2);
	int b=query(v[t].left+1,l,r,(tr+tl)/2+1,tr);
	return min(a,b);
}
int solve(){
 int n;cin>>n;
 vector<pii>v(n);
 rep3(n){
 	int l,r;cin>>l>>r;
 	update(0,l,r,1,0,1e9);
 	v[i].x=l;
 	v[i].y=r;
 }
 for(int i=0;i<n;i++){
 	if(query(0,v[i].x,v[i].y,0,1e9)>1){
 		cout<<i+1<<endl;return 0;
 	}
 }
 cout<<-1<<endl;
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