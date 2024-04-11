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

int m, h1, a1, h2, a2;
int A1, B1, A2, B2;

int go[24][1000111];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> m >> h1 >> a1 >> A1 >> B1 >> h2 >> a2 >> A2 >> B2;

	for (int i = 0; i < m; i++) go[0][i] = (i * 1ll * A2 + B2) % m;

	for (int i = 1; i < 23; i++) for (int j = 0; j < m; j++) go[i][j] = go[i - 1][go[i - 1][j]];

	long long ans = 0;
	while (h1 != a1) {
		ans++;

		h1 = (h1 * 1ll * A1 + B1) % m;

		h2 = go[0][h2];
		if (ans > m + 5) break;
	}
	if (h1 == a1 && h2 == a2) {
		cout << ans << endl;
		return 0;
	}
	if (ans > m + 5) {
		puts("-1");
		return 0;
	}
	ans++;
	int cy = 1;
	h1 = (h1 * 1ll * A1 + B1) % m;
	h2 = go[0][h2];

	while (h1 != a1) {
		cy++;
		ans++;

		h1 = (h1 * 1ll * A1 + B1) % m;

		h2 = go[0][h2];
		if (cy > m + 5) break;
	}
	if (h1 == a1 && h2 == a2) {
		cout << ans << endl;
		return 0;
	}
	if (cy > m + 5) {
		puts("-1");
		return 0;
	}
	for (int i = 0; i < m + 5; i++) {
		ans += cy;
		for (int j = 0; j < 23; j++) if (cy & pw(j)) h2 = go[j][h2];
		if (h2 == a2) {	
			cout << ans << endl;
			return 0;
		}
	}
	puts("-1");


	return 0;
}