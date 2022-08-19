#include<cstdio>
#include<algorithm>
#include<iostream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 200005, INF = 100000000;

P p[MX];

int main(){
	int n, m, l, x, y, w, v; ll ans;
	scanf("%d",&n);
	rep(i,n){ scanf("%d",&p[i].fi); p[i].se = i;}
	rep(i,n){ scanf("%d",&p[i+n].fi); p[i+n].se = i;}
	sort(p,p+n*2);
	
	scanf("%d",&m);
	
	l = 0; ans = 1;
	while(l < n*2){
		x = p[l].fi; y = -1; w = v = 0;
		while(l < n*2 && p[l].fi == x){
			w++;
			if(p[l].se == y) v++;
			y = p[l].se;
			l++;
		}
		
		rrep(i,w){
			ans *= i;
			while(v > 0 && ans%2 == 0){ ans /= 2; v--;}
			ans %= m;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}