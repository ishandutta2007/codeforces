#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<bitset>
#include<iostream>
#include<sstream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define pb push_back
#define snuke srand((unsigned)clock())
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 300005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

// Binary Indexed Tree
struct bit{
	vector<ll> d; int sz;
	bit(){}
	bit(int mx){
		sz = 1; while(sz < mx) sz <<= 1;
		d.resize(sz+1); init(mx);
	}
	void init(int mx, bool fil=false){
		sz = 1; while(sz < mx) sz <<= 1;
		if(fil){ rrep(i,sz) d[i] = i&-i;} else { rrep(i,sz) d[i] = 0;}
	}
	void add(int i, ll x=1){ for(;i<=sz;i+=i&-i) d[i] += x;}
	void add2(int i, int j, ll x=1){ add(i,x); add(j,-x);}
	ll sum(int i){
		ll x = 0; for(;i;i-=i&-i) x += d[i];
		return x;
	}
	ll sum2(int i, int j){ return sum(j)-sum(i);}
	int kth(int k){
		if(k > d[sz]) return -1;
		int i = sz>>1, p = 0;
		while(i){
			if(d[p+i] < k) p += i, k -= d[p];
			i >>= 1;
		}
		return p+1;
	}
};
//

int a[MX], b[MX];
bit bit(MX);

int main(){
	int n, m, x, y, t, xa, ya, xs, ys, xt, yt, x2s, y2s, x2t, y2t;
	scanf("%d",&n);
	rrep(i,n){
		scanf("%d",&a[i]);
		b[a[i]] = i;
	}
	
	rrep(i,n) if(b[i-1] > b[i]) bit.add(i);
	
	scanf("%d",&m);
	rep(mi,m){
		scanf("%d%d%d",&t,&x,&y);
		if(t==1){
			cout << bit.sum2(x,y)+1 << endl;
		} else {
			xa = a[x]; ya = a[y];
			if(b[xa-1] > b[xa]) xs = 1; else xs = 0;
			if(b[ya-1] > b[ya]) ys = 1; else ys = 0;
			if(b[xa] > b[xa+1]) x2s = 1; else x2s = 0;
			if(b[ya] > b[ya+1]) y2s = 1; else y2s = 0;
			swap(a[x],a[y]); swap(b[xa],b[ya]);
			if(b[xa-1] > b[xa]) xt = 1; else xt = 0;
			if(b[ya-1] > b[ya]) yt = 1; else yt = 0;
			if(b[xa] > b[xa+1]) x2t = 1; else x2t = 0;
			if(b[ya] > b[ya+1]) y2t = 1; else y2t = 0;
			bit.add(xa,xt-xs);
			bit.add(ya,yt-ys);
			if(ya-xa != 1) bit.add(xa+1,x2t-x2s);
			if(xa-ya != 1) bit.add(ya+1,y2t-y2s);
			//printf("%d , %d\n", xa, ya);
		}
	}
	
	return 0;
}