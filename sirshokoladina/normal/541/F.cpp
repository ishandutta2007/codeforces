#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 1100;
const int inf = 1000 * 1000 * 1000;

int ans[2][size][size];
int t[size];
int n, tim;
int q[size];
int ord[size];

bool comp(int i, int j) {
	return t[i] > t[j];
}

int main() {
    /*
    freopen("input.txt", "w", stdout);
    int n = 1000;
    int tim = 100;

    cout << n << ' ' << tim << endl;
    for (int i = 0; i < n; i++)
    	cout << rand() % 10 + 1 << ' ' << rand() % 1000 + 1 << endl;

    return 0;
    */
	
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &tim);

    for (int i = 0; i < n; i++) {
    	scanf("%d%d", &t[i], &q[i]);
    	ord[i] = i;
    }

    sort(ord, ord + n, comp);
    for (int i = 0; i <= n; i++)
    	for (int j = 0; j <= n; j++)
    		ans[0][i][j] = -inf; 
    ans[0][0][1] = 0;
	
	int p = 0;
	int tans = 0;

    for (int i = 0; i <= tim; i++) {
    	for (int j = 0; j <= n; j++)
    		for (int k = 0; k <= n; k++)
    			ans[p ^ 1][j][k] = -inf; 
    	for (int j = 0; j <= n; j++)
    		for (int k = 0; k <= n; k++) {
    			if (ans[p][j][k] < 0)
    				continue;
    			//cout << i << ' ' << j << ' ' << k << ' ' << ans[p][j][k] << endl;
    			if (j < n) {
	    			ans[p][j + 1][k] = max(ans[p][j + 1][k], ans[p][j][k]);
    				if (k > 0 && t[ord[j]] + i <= tim)
    					ans[p][j + 1][k - 1] = max(ans[p][j + 1][k - 1], ans[p][j][k] + q[ord[j]]);
    			}
    			ans[p ^ 1][j][min(n, k * 2)] = max(ans[p ^ 1][j][min(n, k * 2)], ans[p][j][k]);
    			//ans[p ^ 1][j][k] = max(ans[p ^ 1][j][k], ans[p][j][k]);
    		}

    	p ^= 1;
    }

    for (int j = 0; j <= n; j++)
    	for (int k = 0; k <= n; k++)
    		tans = max(tans, ans[p][j][k]);

    cout << tans << endl;

    //cerr << (clock() + 0.0) / CLOCKS_PER_SEC << endl;

    return 0;
}