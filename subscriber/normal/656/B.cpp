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

int n;
int m[22], r[22];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> m[i];
	for (int i = 0; i < n; i++) {
		cin >> r[i];
		r[i] %= m[i];
		if (r[i] < 0) r[i] += m[i];
	}		
	int s = 0;
	for (int i = 0; i < 10000000; i++) {
		int ok = 0;
		for (int j = 0; j < n; j++) if (i % m[j] == r[j]) {
			ok = 1;
			break;
		}
		s += ok;
	}
	double t = s / 1e7;
	printf("%.10lf\n", t);

	return 0;
}