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
#define each(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define pb push_back
#define snuke srand((unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 100005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

ll x[2][MX];

int main(){
	int n, k, a,b,c,d; ll pre, ans = -1;
	scanf("%d%d",&n,&k);
	
	rep(i,n){
		scanf("%d.%d.%d.%d",&a,&b,&c,&d);
		x[0][i] = (ll)a<<24|b<<16|c<<8|d;
	}
	sort(x[0],x[0]+n);
	
	a = 0; b = 1; d = n;
	for(ll i = (1ll<<32)-2; i >= (1ll<<31); i-=i&-i){
		pre = -1; c = 0;
		rep(j,d){
			x[a][j] &= i;
			if(pre != x[a][j]) x[b][c++] = pre = x[a][j];
		}
		if(c == k) ans = i;
		d = c; swap(a,b);
	}
	
	if(ans == -1) puts("-1"); else {
		printf("%d.%d.%d.%d\n",int(ans>>24),int(ans>>16&255),int(ans>>8&255),int(ans&255));
	}
	
	return 0;
}