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

int x, y, xx, yy;
int n;


int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> x >> y >> xx >> yy;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		long long v1 = (a * 1ll * x + b * 1ll * y + c);
		long long v2 = (a * 1ll * xx + b * 1ll * yy + c);

		if (v1 < 0 && v2 > 0 || v1 > 0 && v2 < 0) ans++;
	}
	cout << ans << endl;
	return 0;
}