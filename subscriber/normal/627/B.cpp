#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, k, a, b, q;
int o[N];
long long s1[N], s2[N];

void add1(int x, int v) {
	while (x < n) {
		s1[x] += v;
		x |= (x + 1);
	}
}

long long get1(int x) {
	long long r = 0;
	while (x >= 0) {
		r += s1[x];
		x = (x & (x + 1)) - 1;
	}
	return r;
} 
void add2(int x, int v) {
	while (x < n) {
		s2[x] += v;
		x |= (x + 1);
	}
}

long long get2(int x) {
	long long r = 0;
	while (x >= 0) {
		r += s2[x];
		x = (x & (x + 1)) - 1;
	}
	return r;
} 

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> k >> b >> a >> q;

	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int d, add;
			cin >> d >> add;
			d--;
			add1(d, min(add, max(0, a - o[d])));
			add2(d, min(add, max(0, b - o[d])));
			o[d] += add;
		} else {
			int p;
			cin >> p;
			p--;
			long long ans = get1(p - 1) + get2(n - 1) - get2(p + k - 1);
			cout << ans << endl;
		}
	}

	return 0;
}