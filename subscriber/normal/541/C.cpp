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
int a[222];
int f[222];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	long long gc = 1;
	int ma = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) f[j] = 0;
		int x = i;
		int t = 1;
		int cy;
		int pred;

		for(;;) {
			if (f[x] != 0) {
				cy = t - f[x];
				pred = f[x] - 1;
				break;
			}
			f[x] = t;
			x = a[x];
			t++;
		}
		gc = gc / __gcd(gc, 1ll * cy) * cy;
		ma = max(ma, pred);
	}
	long long ans = gc;
	while (ans < ma) ans += gc;
	cout << ans << endl;
	return 0;
}