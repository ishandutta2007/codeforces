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

int f[N];
int q[5];

int n, k;

int slow(int n, int k) {
	f[0] = 0;
	
	for (int i = 1; i <= n; i++) {
		q[0] = q[1] = q[2] = 0;

		q[f[i - 1]] = 1;
		if (i % 2 == 0) {
			if (k % 2) q[f[i / 2]] = 1; else q[0] = 1;
		} 
		int h = 0;
		while (q[h]) h++;
		f[i] = h;
	}
	return f[n];
}

int my(int n, int k) {
	if (n == 0) return 0;
	if (k % 2 == 0) {
		if (n == 1) return 1;
		if (n == 2) return 2;
		return (n - 1) % 2;
	} else {
		if (n == 1 || n == 3) return 1;
		if (n % 2) return 0;
		int q[5];
		q[0] = q[1] = q[2] = q[3] = 0;
		q[my(n - 1, k)] = 1;
		if (n % 2 == 0) q[my(n / 2, k)] = 1;
		int h = 0;
		while (q[h])h++;
		return h;
	}
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> k;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		ans ^= my(x, k);
	}
	if (ans) puts("Kevin"); else puts("Nicky");
	return 0;
}