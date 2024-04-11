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

char s[1000111];

pair<int, int> q[33];

int a[33];

int main(){
	#ifdef home
		freopen(TASK".in","r",stdin);	
		freopen(TASK".out","w",stdout);
	#endif		
	scanf("%d%d\n", &n, &k);
	gets(s);

	int l = strlen(s);

	for (int i = 0; i < k; i++) q[i].S = i;

	long long sum = 1;

	for (int i = 0; i < l; i++) {
		int u = s[i] - 'a';
		q[u].F = i + 1;

		long long t = (sum - a[u] + M) % M;

		sum = (sum + t) % M;

		a[u] = (a[u] + t) % M;
	}
	sort(q, q + k);

	for (int i = 0; i < n; i++) {
		int u = q[i % k].S;

		long long t = (sum - a[u] + M) % M;

		sum = (sum + t) % M;

		a[u] = (a[u] + t) % M;
	}

	cout << sum << endl;


	return 0;
}