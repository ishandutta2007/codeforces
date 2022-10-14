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
// for max
const int maxn=3e5+5;
bool Q;
struct Line {
	mutable int k, m, p;
	 bool operator<(const Line& o) const {
        return Q ? p < o.p : k < o.k;
    }
};

struct LineContainer : multiset<Line> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const int inf = LLONG_MAX;
	int div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(int k, int m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	int query(int x) {
		assert(!empty());Q=1;
		auto l = *lower_bound({0,0,x});Q=0;
		return l.k * x + l.m;
	}
}cht;
LineContainer t[4*maxn];
void add_line(int v,int tl,int tr,int l,int r,pii p){
	 if(l>tr || tl>r)return;
	 if(l<=tl && tr<=r){
	 	 t[v].add(p.x,p.y);
	 	 return;
	 }
	 add_line(2*v,tl,(tl+tr)/2,l,r,p);
	 add_line(2*v+1,(tl+tr)/2+1,tr,l,r,p);
}
int query(int v,int tl,int tr,int idx,int x){
	if(idx>tr || idx<tl )return -(8*1e18);
	int ans=-(8*1e18);
	if(!t[v].empty())ans=t[v].query(x);
	if(tl==tr)return ans;
	return max({ans,query(2*v,tl,(tl+tr)/2,idx,x),query(2*v+1,(tl+tr)/2+1,tr,idx,x)});
}
int solve(){
 int n;cin>>n;
 vector<pii>lines(n+1);
 vector<int>q(n+1,1e18);
 vector<int>used(n+1,0);
 vector<int>is(n+1,0);
 for(int i=1;i<=n;i++){
 	int t;cin>>t;
 	if(t==1){
 		cin>>lines[i];
 		is[i]=1;
 	}
 	else if(t==2){
 	   int idx;cin>>idx; 
       used[idx]=1;
       add_line(1,1,maxn-1,idx,i-1,lines[idx]);
 	}
 	else cin>>q[i];
 }
 for(int i=1;i<=n;i++){
 	if(!used[i] && is[i]){
 		add_line(1,1,maxn-1,i,maxn-1,lines[i]);
 	}
 }
 for(int i=1;i<=n;i++){
 	if(q[i]!=1e18){
 		int val=query(1,1,maxn-1,i,q[i]);
 		if(val==-8e18)cout<<"EMPTY SET"<<endl;
 		else cout<<val<<endl;
 	}
 }
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