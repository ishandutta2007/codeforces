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
#define N 411111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int n, k, x;
int a[N];
long long L[N], R[N];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> k >> x;
	for (int i = 0; i< n; i++) scanf("%d", &a[i]);

	L[0] = 0;
	for (int i = 0; i < n; i++) L[i + 1] = L[i] | a[i];
	R[n] = 0;
	for (int i = n - 1; i >= 0; i--) R[i] = R[i + 1] | a[i];


	long long ans = L[n];
	for (int i = 0; i < n; i++) {
		long long t = a[i];
		for (int j = 0; j < k; j++) t *= x;

		long long s = t | L[i] | R[i + 1];
		ans = max(ans, s);
	}
	cout << ans << endl;
	return 0;
}