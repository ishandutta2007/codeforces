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

const int MX = 100005, INF = 1000000000, mod = 1000000009;
const ll LI = 100000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int n, m;
ll h[MX], p[MX];

bool f(ll x){
	int pi = 0;
	ll l, r;
	rep(i,n){
		l = p[pi];
		while(pi < m){
			r = p[pi];
			if(r <= h[i]){
				if(h[i]-l > x) break;
			} else if(l >= h[i]){
				if(r-h[i] > x) break;
			} else {
				if(r-l+min(r-h[i],h[i]-l) > x) break;
			}
			pi++;
		}
		if(pi == m) return true;
	}
	return false;
}

int main(){
	cin >> n >> m;
	rep(i,n) cin >> h[i];
	rep(i,m) cin >> p[i];
	
	ll l = -1, r = LI, c;
	while(l+1 < r){
		c = (l+r)/2;
		if(f(c)) r = c; else l = c;
	}
	
	cout << r << endl;
	
	return 0;
}