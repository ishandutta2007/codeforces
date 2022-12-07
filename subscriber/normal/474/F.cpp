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
#define M 1000000007
#define N 211111
using namespace std;
typedef pair<int,int> pt;

int a[N];
pair<int, int> q[N];
int ff[20][N];
int gg[N];

int fm(int x, int y){
	int w = gg[y - x + 1];
	return __gcd(ff[w][x], ff[w][y - pw(w) + 1]);
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) ff[0][i] = a[i];
	for (int i = 1; i < 20; i++)
		for (int j = 0; j < n; j++) if (j + pw(i) <= n) ff[i][j] = __gcd(ff[i - 1][j], ff[i - 1][j + pw(i - 1)]);
	gg[1] = 0;
	for (int i = 2; i <= n; i++) gg[i] = gg[i / 2] + 1;

	for (int i = 0; i < n; i++) q[i] = mp(a[i], i);
	sort(q, q + n);

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		int g = fm(x, y);

		int ans = upper_bound(q, q + n, mp(g, y)) - lower_bound(q, q + n, mp(g, x));
		ans = (y - x + 1) - ans;
		printf("%d\n", ans);
	}	


	return 0;
}