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
int a[N];
int dp[N][60];

const int C = 80;

void calc(int l, int r) {

	for (int i = r - 1; i >= l; i--) {
		if (i == r - 1) {
			int o = 0;

			for (int j = 0; j < 59; j++) {
				if (o == 0) {
					dp[i][j] = 2;
				} else {
					dp[i][j] = 1;
				}
				o++;
				if (o == a[i]) o = 0;
			}
			if (o == 0) {
				dp[i][59] = 2;
			} else {
				dp[i][59] = 1;
			}
			continue;
		}

		int o = 0;

		for (int j = 0; j < 59; j++) {
			if (o == 0) {
				dp[i][j] = 2 + dp[i + 1][(j + 2) % 60];
			} else {
				dp[i][j] = 1 + dp[i + 1][j + 1];
			}
			o++;
			if (o == a[i]) o = 0;
		}
		if (o == 0) {
			dp[i][59] = 2 + dp[i + 1][1];
		} else {
			dp[i][59] = 1 + dp[i + 1][0];
		}
			
	}
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	for (int i = 0; i <= n; i += C) calc(i, min(i + C, n));

	int t;
	scanf("%d\n", &t);
	while (t--) {
		char type;
		scanf("%c", &type);
		if (type == 'C') {
			int x, v;
			scanf("%d%d\n", &x, &v);
			x--;
			a[x] = v;
			calc(x / C * C, min(x / C * C + C, n));
		} else {
			int x, y;
			scanf("%d%d\n", &x, &y);
			x--;
			y--;
			int t = 0;
			while (x % C != 0 && x < y) {
				if (t % a[x] == 0) t++;
				t++;
				x++;				
			}
			while (x < y && min(x + C, n) <= y) {
				int g = dp[x][t % 60];
				t += g;
				x = min(x + C, n);
			}
			while (x < y) {
				if (t % a[x] == 0) t++;
				t++;
				x++;				
			}
			printf("%d\n", t);
		}
	}


	return 0;
}