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
int a[N], s[N], ma[N];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	int k = pw(n + 1) - 1;
	for (int i = 2; i <= k; i++) scanf("%d", &a[i]);

	for (int i = k; i >= 1; i--) {
		ma[i] = 0;
		if (i + i <= k) ma[i] = max(ma[i], ma[i + i] + a[i + i]);
		if (i + i + 1 <= k) ma[i] = max(ma[i], ma[i + i + 1] + a[i + i + 1]);
	}
	
	int ans = 1e9;
	for (int d = 0; d <= 4100; d++) {
		int cur = 0;
		s[1] = 0;

		int bad = 0;
		for (int i = 2; i <= k; i++) {
			int alr = s[i / 2] + a[i] + ma[i];
			if (alr > d) {
				bad = 1;
				break;
			}
			
			cur += d - alr;
			s[i] = s[i / 2] + a[i] + (d - alr);
		}
		if (!bad) ans = min(ans, cur);
	}
	cout << ans << endl;
	return 0;
}