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

int n, p[55];

int ans[55];

int used[55];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);

	long long k;
	cin >> n >> k;
	k--;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) if (!used[j]) {
			long long t;
			if (i > 0 && j < ans[i - 1]) {
				int bad =0;
				for (int k = j + 1; k < n; k++) if (used[k] == 0) bad = 1;
				t = 1 - bad;
			} else {
				int ma = j;
				for (int k = 0; k < i; k++) ma = max(ma, ans[k]);
				
				int r = (n - ma - 1);
				if (r <= 1) t = 1; else t = pw(r - 1);
			}


			if (t <= k) {
				k -= t;
			} else {
				ans[i] = j;
				used[j] = 1;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] + 1;
		if (i + 1 == n) puts(""); else putchar(' ');
	}

	return 0;
}