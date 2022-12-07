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
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

int a[N];
int n;

int pv(int a, int b) {
	if (b == 0) return 1;
	long long r = pv(a, b / 2);
	r = r * r % n;
	if (b % 2) r = r * a % n;
	return r;
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	if (n == 4) {
		puts("YES");
		puts("1");
		puts("3");
		puts("2");
		puts("4");
		return 0;
	}

	for (int i = 2; i < n; i++) if (n % i == 0) {
		puts("NO");
		return 0;
	}
	puts("YES");

	a[0] = 1;
	for (int i = 1; i < n - 1; i++) a[i] = (i + 1) * 1ll * pv(i, n - 2) % n;
	a[n - 1] = n;

	set<int> S;
	for (int i = 0; i < n; i++) {
		if (S.find(a[i]) != S.end()) puts("!");
		S.insert(a[i]);
	}

	for (int i = 0; i < n; i++) printf("%d\n", a[i]);

	return 0;
}