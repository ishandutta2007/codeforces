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

int a[MX], b[MX];
P q[MX]; int qs, qt;

ll f(int i, int x){
	return q[i].fi+q[i].se*x;
}

bool check(int i){
	ll a1 = q[i].se, b1 = q[i].fi;
	ll a2 = q[i+1].se, b2 = q[i+1].fi;
	ll a3 = q[i+2].se, b3 = q[i+2].fi;
	return (long double)(b1-b2)/(a2-a1) < (long double)(b1-b3)/(a3-a1);
}

int main(){
	int n; ll now;
	scanf("%d",&n);
	
	rep(i,n){
		scanf("%d",&a[i]);
	}
	rep(i,n){
		scanf("%d",&b[i]);
	}
	
	q[0] = P(0,b[0]);
	qs = 0; qt = 1;
	
	rrep(i,n-1){
		while(qs+1<qt){
			if(f(qs,a[i]) < f(qs+1,a[i])) break;
			qs++;
		}
		now = f(qs,a[i]);
		if(now > (ll)INF*INF) continue;
		
		while(qs+1<qt){
			q[qt] = P(now,b[i]);
			if(check(qt-2)) break;
			qt--;
		}
		q[qt++] = P(now,b[i]);
	}
	
	cout << q[qt-1].fi << endl;
	
	return 0;
}