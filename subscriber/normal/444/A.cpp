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

int n, m;
int a[N];

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	double ans = 0;
	for (int i = 0; i < m; i++) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		x--;
		y--;
		ans = max(ans, (a[x] + a[y]) / 1. / c); 
	}
	printf("%.10lf\n", ans);
	return 0;
}