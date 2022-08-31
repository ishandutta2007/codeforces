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
typedef pair<ll,ll> P;

const int MX = 100005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int d[MX]; ll x[MX];
P q[105][MX]; int qs[105], qt[105];

ll f(int p, int i, int t){
	ll a = q[p][i].se, b = q[p][i].fi;
	return b+(a+1)*(x[t]-x[max(0ll,a)]);
}

bool check(int j, int i, int t){
	ll a1 = q[j][i].se+1, b1 = q[j][i].fi+a1*(x[t]-x[max(0ll,a1-1)]);
	ll a2 = q[j][i+1].se+1, b2 = q[j][i+1].fi+a2*(x[t]-x[max(0ll,a2-1)]);
	ll a3 = q[j][i+2].se+1, b3 = q[j][i+2].fi+a3*(x[t]-x[max(0ll,a3-1)]);
	return (b1-b2)*(a3-a1) < (b1-b3)*(a2-a1);
}

int main(){
	int n, m, p, a, b; ll ans = 0, now;
	scanf("%d%d%d",&n,&m,&p);
	
	rrep(i,n-1){
		scanf("%d",&a);
		d[i] = d[i-1]+a;
	}
	
	rep(i,m){
		scanf("%d%d",&a,&b);
		x[i] = b-d[a-1];
	}
	
	sort(x,x+m);
	
	rrep(i,m-1) ans += (x[i]-x[i-1])*i;
	
	rep(j,p+1){
		q[j][0] = P(0,-1);
		qs[j] = 0; qt[j] = 1;
	}
	
	rep(i,m){
		drep(j,p){
			while(qs[j]+1<qt[j]){
				if(f(j,qs[j],i) > f(j,qs[j]+1,i)) break;
				qs[j]++;
			}
			now = f(j,qs[j],i);
			
			//cout << i << " " << j << " " << a << endl;
			while(qs[j+1]+1<qt[j+1]){
				q[j+1][qt[j+1]] = P(now,i);
				if(check(j+1,qt[j+1]-2,i)) break;
				qt[j+1]--;
			}
			q[j+1][qt[j+1]++] = P(now,i);
		}
	}
	
	//cout << ans << endl;
	cout << ans-q[p][qt[p]-1].fi << endl;
	
	return 0;
}