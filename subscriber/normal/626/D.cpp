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
int e[N];
long long a[N], b[N];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> e[i];
	sort(e, e + n);

	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) a[e[j] - e[i]]++;


	for (int i = 1; i <= 5000; i++) if (a[i]) for (int j = 1; j <= 5000; j++) b[i + j] += a[i] * a[j];

	long long ans = 0;
	long long s = 0;
	for (int i = 1; i <= 10000; i++) {
		ans += s * a[i];
		s += b[i];
	}
	int C = n * (n - 1) / 2;

	double out = ans / 1. / C / C / C;
	printf("%.10lf\n", out);

	return 0;
}