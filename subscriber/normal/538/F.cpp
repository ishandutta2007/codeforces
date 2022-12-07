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

int n;
int a[N], ans[N];
int mag = 555;

int l[N], r[N], oldl[N], oldr[N], cur[N];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	for (int k = 1; k <= min(n - 1, mag); k++) {
		int t = 0;
		for (int i = 1; i < n; i++) if (a[i] < a[(i - 1) / k]) t++;
		ans[k] = t;
	}
	for (int k = mag + 1; k <= n - 1; k++) {
		for (int i = 0; i <= k; i++) {
			l[i] = i * k + 1;
			r[i] = min(k * (i + 1), n - 1);

			if (l[i] >= n) break;
		}
		if (k == mag + 1) {
			for (int i = 0; i <= k; i++) {
				if (l[i] >= n) break;
				oldl[i] = l[i];
				oldr[i] = r[i];
				for (int j = l[i]; j <= r[i]; j++) if (a[i] > a[j]) cur[i]++;
			}
		} else {
			for (int i = 0; i <= k; i++) {
				if (l[i] >= n) break;
				while (oldl[i] < l[i]) {
					if (a[i] > a[oldl[i]]) cur[i]--;
					oldl[i]++;
                                }
                                while (oldr[i] < r[i]) {
                                	oldr[i]++;
					if (a[i] > a[oldr[i]]) cur[i]++;                                	
                                }
			}
		}
		int t = 0;
		for (int i = 0; i <= k; i++) {
			if (l[i] >= n) break;
			t += cur[i];
		}
		ans[k] = t;

	}

	for (int i = 1; i <= n - 1; i++) {
		printf("%d", ans[i]);
		if (i == n - 1) puts(""); else putchar(' ');
	}
	return 0;
}