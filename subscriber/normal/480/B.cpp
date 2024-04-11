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

int n, l, x, y;
int a[N];
set<int> Q;
map<int, int> was;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> l >> x >> y;
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	int xx = 0, yy = 0;

	for (int i = 0; i < n; i++) {
		if (was[a[i] - x]) xx = 1;
		if (was[a[i] - y]) yy = 1;
		was[a[i]] = 1;
	}

	if (xx && yy) {
		puts("0");
//		puts("");
		return 0;
	}
	if (xx || yy) {
		puts("1");
		if (xx) cout << y << endl; else cout << x << endl;
		return 0;
	}

	int sol = -1;

	for (int i = 0; i < n; i++) {
		int t = a[i] - x;

		if (t >= 0) Q.insert(t);

		t = a[i] + x;

		if (t <= l) Q.insert(t);
	}

	for (int i = 0; i < n; i++) {
		if (Q.find(a[i] + y) != Q.end()) {
			sol = a[i] + y;
		}
		if (Q.find(a[i] - y) != Q.end()) {
			sol = a[i] - y;
		}
	}

	if (sol != -1) {
		puts("1"); 
		cout << sol << endl;
	} else {
		puts("2");
		cout << x << " " << y << endl;
	}		



	return 0;
}