#include<cstdio>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef pair<P,int> Q;

const int MX = 105, INF = 2000000000;

int main(){
	int n, m, q, x, y, a, b, d;
	ll ans = 0;
	scanf("%d%d%d%d%d",&n,&m,&x,&y,&q);
	
	rep(i,q){
		scanf("%d%d",&a,&b);
		d = INF;
		if(a > 0) d = min(d,(n-x)/a);
		if(a < 0) d = min(d,(x-1)/(-a));
		if(b > 0) d = min(d,(m-y)/b);
		if(b < 0) d = min(d,(y-1)/(-b));
		ans += d;
		x += a*d;
		y += b*d;
	}
	cout << ans;
	
	return 0;
}