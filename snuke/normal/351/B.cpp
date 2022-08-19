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
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 3005, INF = 1000000000, mod = 1000000007;
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

int main(){
	int n, c = 0, x;
	
	cin >> n;
	
	bit d(MX);
	
	rep(i,n){
		cin >> x;
		c += i-d.sum(x);
		d.add(x);
	}
	
	if(c&1) printf("%d\n",c*2-1); else printf("%d\n",c*2);
	
	return 0;
}