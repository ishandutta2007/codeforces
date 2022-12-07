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
int a[2000222];
long long lay[33];
long long eq[33];
long long ans = 0;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	cin >> n;
	for (int i = 0; i < pw(n); i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		int x = pw(i);
		for (int j = 0; j < pw(n); j += x) {
			sort(a + j, a + j + x);
		}
		for (int j = 0; j < pw(n); j += 2 * x) {
			for (int k = j; k < j + x; k++) {
				int u = lower_bound(a + j + x, a + j + x + x, a[k]) - a;
				lay[i + 1] += u - (j + x);
				int uu = upper_bound(a + j + x, a + j + x + x, a[k]) - a;
				eq[i + 1] += uu - u;
			}
		}
		ans += lay[i + 1];
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		scanf("%d", &x);
		if (x == 0) {
			printf("%I64d\n", ans);
			continue;
		}
		for (int w = 1; w <= x; w++) {
			long long g = pw(w - 1);
			g = g * g;
			g *= pw(n - w);
			ans -= lay[w];
			lay[w] = g - lay[w] - eq[w];
			ans += lay[w];			
		}
		printf("%I64d\n", ans);
	} 

	return 0;
}