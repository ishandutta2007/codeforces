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

int fu[2000111], inv[2000111];
int n;

int pv(int a, int b)  {
	if (b == 0) return 1;
	long long r = pv(a, b / 2);
	r = r * r % M;
	if (b % 2) r = r * a % M;
	return r;
}


int C(int n, int k) {
	return fu[n] * 1ll * inv[n - k] % M * inv[k] % M;
}

int sol(int n) {
	int ans = 0;
	for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) ans = (ans + C(i + j, i)) % M;
	return ans;
}

int sol2(int n) {
	int t = 2* 1ll * fu[2*n-1];
	int z = pv(fu[n] * 1ll * fu[n - 1] % M, M - 2);
	t = t * 1ll * z % M;
	return (t + M - 1) % M;
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	fu[0] = 1;
	for (int i = 1; i <= 2e6 + 5; i++) fu[i] = fu[i - 1] * 1ll * i % M;
//	for (int i = 0; i <= 2e6 + 5; i++) inv[i] = pv(fu[i], M - 2);

	cin >> n;
	cout << sol2(n + 1) << endl;

/*	for (int i = 1; i <= 10; i++) cout << sol(i) << ",";
	cout << endl;
	for (int i = 1; i <= 10; i++) cout << sol2(i) << ",";*/

	return 0;
}