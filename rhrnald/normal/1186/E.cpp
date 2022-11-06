#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <complex>

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3c3c3c3c;
const ll LINF = 1ll*INF*INF*2;

const int N = 1001;
int n,m,q;
string s;
ll a, b, c,d;
ll x[N][N];
ll f(ll a, ll b, bool inv) {
	if(!a || !b) return 0;
	if(a<=n && b<=m) {
		if(inv) return 1ll*a*b-x[a][b];
		else return x[a][b];
	}


	if(a<=n) {
		if(b<=m+m) return f(a,m,inv)+f(a, b-m, !inv);
		ll L=m+m;
		ll t=a*m;
		while(L+L<=b) L=L+L, t=t+t;
		return t+f(a, b-L, !inv);
	}
		if(a<=n+n) return f(n,b,inv)+f(a-n, b, !inv);
		ll L=n+n;
		ll t=n*b;
		while(L+L<=a) L=L+L, t=t+t;
		return t+f(a-L, b, !inv);

}
int main(void){
	scanf("%d%d%d", &n, &m, &q);
	for(int i=0; i<n; i++) {
		cin >> s;
		for(int j=0; j<m; j++) x[i+1][j+1]=s[j]=='1';
	}

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			x[i][j]=x[i][j]+x[i][j-1]+x[i-1][j]-x[i-1][j-1];
		}
	}
	while(q--) {
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		printf("%lld\n", f(c,d,0)+f(a-1,b-1,0)-f(a-1,d,0)-f(c,b-1,0));
	}
}