#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <vector>

#define ll long long int
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(a, b) for(int a = 0; a < (b); a++)
#define iter(a) typeof(a.begin())
#define foreach(a, it) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)

using namespace std;

const long double EPS = 1e-8;
const int INF = 1000000001;
const int MAXN = 4002;
const int MAXT = 86400;

int st[MAXN];
int d[MAXN];
int lt[MAXN];
int olt[MAXN];

int dp[2 * MAXT + 1];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n, k;
	scanf("%d%d", &n, &k);
	FOR(i, n) {
		scanf("%d%d", &st[i], &d[i]);
		st[i]--;
	}
	clr(dp);
	clr(olt);
	olt[0] = 2 * MAXT + 1;
	clr(lt);

	FOR(i, n) {
		int en = st[i] + d[i];
		int j = MAXN - 1;
		while (j >= 0 && olt[j] <= st[i]) {
		    if (j != MAXN - 1)
                	for (int g = olt[j + 1]; g < olt[j]; ++g)
                    		dp[g] = j;
			lt[j] = st[i];
			--j;
		}
		for (int g = olt[j + 1]; g < st[i]; ++g)
			dp[g] = j;
		//lt[j + 2] = st[i] - 1;
		while(j >= 0 && olt[j] <= en) {
			lt[j + 1] = olt[j];
			--j;
		}
		lt[j + 1] = en;
		while (j >= 0) {
			lt[j + 1] = max(lt[j + 1], min(olt[j], olt[j + 1] + d[i]));
			--j;
		}
		lt[0] = olt[0];
		//cerr << '\n';
		FOR(g, MAXN) {
			olt[g] = lt[g];
			//cerr << olt[g] << ' ';
		}
	}
	int j = MAXN - 1;
	while (j >= 0) {
	    	if (j != MAXN - 1)
			for (int g = olt[j + 1]; g < olt[j]; ++g)
				dp[g] = j;
		--j;
	}
    	int p = 0;
	int mx = 0;
   	FOR(i, MAXT) {
        	if (st[p] == i)
            		p++;
        	int w = k - dp[i];
        	if (w < 0) continue;
        	int t = 0;
        	if (p + w >= n)
            		t = MAXT - i;
        	else
            		t = st[p + w] - i;
        	mx = max(t, mx);
    	}
    	cout << mx;
	return 0;
}