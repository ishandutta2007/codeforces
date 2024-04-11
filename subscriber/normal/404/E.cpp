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
using namespace std;
typedef pair<int,int> pt;

int st = 0;
int f[5000333];
int n;
char a[2000222];

bool can(int z) {
	st++;
	int x = 2e6;
	z += 2e6;
	f[x] = st;
	for (int i = 0; i < n; i++) {
		if (a[i] == 'L' && z != x - 1) x--;
		if (a[i] == 'R' && z != x + 1) x++;
		if (i == n - 1) {
			if (f[x] == st) return 0;
			return 1;
		}
		f[x] = st;
	}
	
}

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	gets(a);
	n = strlen(a);
	if (can((int)1e9)) {
//		puts("one");
		cout << 1 << endl;
	} else {
		int ans = 0;
		for (int i = -1; i < 2; i += 2) if (can(i)) {
			int l = 1;
			int r = 1e6 + 100;
			while (l < r) {
				int c = (l + r + 1) / 2;
				if (can(c * i)) l = c; else r = c - 1;
			}
			ans += l;
		}
		cout << ans << endl;
	}
	return 0;
}