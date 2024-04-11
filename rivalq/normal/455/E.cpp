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

const int N = 1e5+5;

// for max
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
};

LineContainer t[4*N];

const int I = -1e9;



int solve(){
 		int n; cin >> n;

 		vector<int>a(n+1),pre(n+1);

 		rep(i,1,n+1){
 			cin >> a[i];
 			pre[i] += pre[i-1] + a[i];
 		}

 		function<void(int,int,int)> build = [&](int v,int l,int r){
 			for(int k = l; k <= r; k++){
 				t[v].add(-a[k],pre[k] - a[k]*k);
 			}
 			if(l == r){
 				return;
 			}else{
 				int mid = (l + r)/2;
 				build(2*v,l,mid);
 				build(2*v+1,mid+1,r);
 			}
 		};
 		build(1,1,n);
 		int s;
 		function<int(int,int,int,int,int)> query = [&](int v,int tl,int tr,int l,int r){
 			if(tl > r or l > tr)return I;
 			if(l <= tl and tr <= r){
 				return t[v].query(s);
 			}
 			int mid = (tl + tr)/2;
 			return max(query(2*v,tl,mid,l,r),query(2*v+1,mid+1,tr,l,r));
 		};	

 		int m; cin >> m;
 		rep(i,0,m){
 			int x,y; cin >> x >> y;
 			int L = y - x + 1;
 			s = x - y;
 			auto ans = query(1,1,n,L,y);
 			cout << -ans + pre[y] << endl;
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