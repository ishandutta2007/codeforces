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
#define N 511111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

char a[N], s[N];
int p[N];
int have[N], last[N];
long long dp[N], sum1[N], sum2[N];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	gets(a);
	gets(s);
	int n = strlen(a);
	int k = strlen(s);
	int kk = k;
	s[k++] = '#';
	for (int i = 0; i < n; i++) s[k++] = a[i];

	p[0] = -1;
	for (int i = 1; i < k; i++) {
		int x = p[i - 1];
		while (x != -1 && s[x + 1] != s[i]) x = p[x];
		if (s[x + 1] == s[i]) p[i] = x + 1; else p[i] = -1;
		if (p[i] == kk - 1) have[i - kk - 1] = 1;
	}
	for (int i = 0; i < n; i++) {
		if (have[i]) last[i] = i; else {
			if (i == 0) last[i] = -1; else last[i] = last[i - 1];
		}
	}
	dp[-1 + 5] = 1;
	sum1[-1 + 5] = 1;
	sum2[-1 + 5] = 1;

	for (int i = 0; i < n; i++) {
		int v = last[i] - kk;
		if (v < -1) {
			dp[i + 5] = 0;
		} else {
			dp[i + 5] = sum2[v + 5];
		}
		sum1[i + 5] = (dp[i + 5] + sum1[i - 1 + 5]) % M;

		sum2[i + 5] = (dp[i + 5] + sum1[i - 1 + 5] + sum2[i - 1 + 5]) % M;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) ans = (ans + dp[i + 5]) % M;
	cout << ans << endl;

	return 0;
}