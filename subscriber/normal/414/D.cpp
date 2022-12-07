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

int n, k, p;
vector<int> a;
long long s[N];
vector<int> v[N];

void rec(int x, int p, int d) {
	if (x != 0) a.pb(d);
	for (int i = 0; i < v[x].size(); i++) if (v[x][i] != p) rec(v[x][i], x, d + 1);
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> k >> p;
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	rec(0, -1, 0);
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++) s[i + 1] = s[i] + a[i];
	int l = 0;
	int r = min((int)a.size(), k);
//	for (int i = 0; i < a.size(); i++) cout << a[i] << " " ;
//	cout << endl;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (mid == 0) {
			l = mid;
			continue;
		}
		int ok = 0;
		for (int i = mid - 1; i < a.size(); i++) {
			if (a[i] * 1ll * mid - (s[i + 1] - s[i - mid + 1]) <= p) ok = 1;
		}
		if (ok) l = mid; else r = mid - 1;
	}
	cout << l << endl;
	return 0;
}