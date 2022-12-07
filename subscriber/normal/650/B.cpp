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

int a, b, n, T;
string s;

long long le[1000111], ri[1000111];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n >> a >> b >> T;
	cin >> s;

	long long mt = 1;
	if (s[0] == 'w') mt += b;
	if (mt > T) {
		puts("0");
		return 0;
	}
	
	ri[0] = 0;
	for (int i = 1; i < n; i++) {
		ri[i] = ri[i - 1] + a + 1;
		if (s[i] == 'w') ri[i] += b;
	}

	le[0] = 0;
	for (int i = 1; i < n; i++) {
		le[i] = le[i - 1] + a + 1;
		if (s[n - i] == 'w') le[i] += b;
	}

	if (ri[n - 1] + mt <= T || le[n - 1] + mt <= T) {
		cout << n << endl;
		return 0;
	}
	int ans = 1;
	for (int i = 1; i < n; i++) if (mt + le[i] <= T || mt + ri[i] <= T) ans = max(ans, i + 1);

	int u = n - 1;
	for (int i = 1; i < n; i++) {
		while (u > 0) {
			long long tt = mt + ri[i] + i * 1ll * a + le[u];
			if (tt > T) u--; else break;
		}
		if (u > 1) ans = max(ans, i + u + 1); 
	}
	u = n - 1;
	for (int i = 1; i < n; i++) {
		while (u > 0) {
			long long tt = mt + le[i] + i * 1ll * a + ri[u];
			if (tt > T) u--; else break;
		}
		if (u > 1) ans = max(ans, i + u + 1); 
	}
	cout << ans << endl;

	return 0;
}