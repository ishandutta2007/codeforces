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
#define N 111111
using namespace std;
typedef pair<int,int> pt;

int n, m;
int ans[111][111];

vector<int> gen(int x, long long s, int p, int mul) {
	if (x == 0) {
		vector<int> ret;
		int g = sqrt(s) + 1e-15;
		if (g * g != s) ret.pb(-1);
		return ret;
	}
	for (long long i = p; i < p + 60; i++) {
		vector<int> t = gen(x - 1, s + i * i * mul * mul, i, mul);
		if (t.size() && t[0] == -1) continue;
		t.pb(i * mul);
		return t;
	}
	vector<int> ret;
	ret.pb(-1);
	return ret;
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> m;
	vector<int> a, b;
	a = gen(m, 0, 1, 1);
	b = gen(n, 0, 1, 1);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) ans[i][j] = b[i] * a[j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) cout << ans[i][j] << " ";
		cout << ans[i][m - 1] << endl;
	}
	for (int i = 0; i < n; i++) {
		int s = 0;
		for (int j = 0; j < m; j++) s += ans[i][j] * ans[i][j];
		int g = sqrt(s) + 1e-15;
		if (g * g != s) puts("!");
	}
	for (int i = 0; i < m; i++) {
		int s = 0;
		for (int j = 0; j < n; j++) s += ans[j][i] * ans[j][i];
		int g = sqrt(s) + 1e-15;
		if (g * g != s) puts("!");
	}
	return 0;
}