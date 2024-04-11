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
int a[N];
map<pt, int> e;


void go(int x) {
	swap(a[x], a[x + 1]);
	if (x > 0 && e[mp(a[x - 1], a[x])]) go(x - 1);
	if (x + 2 < n && e[mp(a[x + 1], a[x + 2])]) go(x + 1);
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[mp(x, y)] = 1;
	}
	for (int i = 0; i < n; i++) a[i] = i + 1;
	for (int i = 1; i < n; i++) if (e[mp(a[i - 1], a[i])]) go(i - 1);
	for (int i = 0; i < n - 1; i++) printf("%d ", a[i]);
	cout << a[n - 1] << endl;
	return 0;
}