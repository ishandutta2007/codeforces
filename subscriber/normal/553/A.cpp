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

int n, a[1111];
int inv[1111];

int C(int n, int k) {
	int r = 1;
	for (int i = 0; i < k; i++) {
		r = r * 1ll * (n - i) % M;
		r = r * 1ll * inv[i + 1] % M;
	}
	return r;
}

int pv(int a, int b) {
	if (b == 0) return 1;
	long long r = pv(a, b / 2);
	r = r * r % M;
	if (b % 2) r = r * a % M;
	return r;
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	for (int i = 1; i <= 1000; i++) inv[i] = pv(i, M - 2);
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	int ans = 1;
	for (int i = n - 1; i >= 0; i--) {
		ans = ans * 1ll * C(sum - 1, a[i] - 1) % M;
		sum -= a[i];
	}
	cout << ans << endl;

	return 0;
}