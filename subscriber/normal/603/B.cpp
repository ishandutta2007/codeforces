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

int n, k;

int was[1000111];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> k;
	int ans = 1;
	if (k == 0) {
		for (int i = 0; i < n - 1; i++) ans = ans * 1ll * n % M;
		cout << ans << endl;
		return 0;
	}
	for (int i = 1; i < n; i++) if (!was[i]) {
		ans = ans * 1ll * n % M;
		int x= i;
		while (!was[x]) {
			was[x] = 1;
			x = x * 1ll * k % n;
		}
	}
	if (k == 1) ans = ans * 1ll * n % M;
	cout << ans << endl;
	return 0;
}