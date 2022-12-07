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

int n, k;
int p[1000111];
int pr[22][1000111];
char ans[1000111], s[1000111];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	scanf("%d%d\n", &n, &k);
	gets(s);
	p[0] = -1;
	for (int i = 1; i < n; i++) {
		int x = p[i - 1];
		while (x != -1 && s[x + 1] != s[i]) x = p[x];
		if (s[x + 1] == s[i]) p[i] = x + 1; else p[i] = -1;
	}
	for (int i = 0; i < n; i++) pr[0][i] = p[i];
	for (int i = 1; i < 21; i++) for (int j = 0; j < n; j++) if (pr[i - 1][j] != -1) pr[i][j] = pr[i - 1][pr[i - 1][j]]; else pr[i][j] = -1;

	for (int i = 0; i < n; i++) {
		ans[i] = '0';
		if (k == 1) ans[i] = '1';

		//kk
		int t = p[i];
		if (t == -1) continue;
		for (int j = 20; j >= 0; j--) {
			if (pr[j][t] == -1) continue;

			int g = pr[j][t];
			int len = i - g;
			int kk = (i + 1) / len;
			if (kk >= k) t = g;
		}
		int len = i - t;
		int kk = (i + 1) / len;
		if (kk == k) ans[i] = '1';

		//kk - 1
		t = p[i];
		for (int j = 20; j >= 0; j--) {
			if (pr[j][t] == -1) continue;

			int g = pr[j][t];
			int len = i - g;
			int kk = (i + 1) / len;
			if (kk - 1 >= k) t = g;
		}
		len = i - t;
		kk = (i + 1) / len;
		if ((i + 1) % len == 0 && kk - 1 == k) ans[i] = '1';
		
	}
	puts(ans);
	return 0;
}