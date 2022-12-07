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

int have[11000111];
int n, k;
int a[N];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		have[a[i]] = 1;
	}
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;

		int ans = 1e9;

		for (int i = 0; i < n; i++) for (int j = 1; j <= k; j++) {
			int s = a[i] * j;
			if (s > x) continue;
			s = x - s;

			if (s == 0) {
				ans = min(ans, j);
				continue;
			}

			for (int d = 1; j + d <= k; d++) if (s % d == 0 && s / d < 10000111 && have[s / d]) ans = min(ans, j + d);
		}
		if (ans == 1e9) ans = -1;
		printf("%d\n", ans);
	}		
	return 0;
}