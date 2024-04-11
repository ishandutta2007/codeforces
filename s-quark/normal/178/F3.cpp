#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)
const int MAXN = 2004;
const int MAXM = 505;

int next[MAXN*MAXM][26];
vector<int> s[MAXN*2];
int size[MAXN*MAXM];
int size1[MAXN*2], d[MAXN*2];
int f[MAXN*2][MAXN];
int f1[MAXN];
int cnt;
char s1[MAXM];

int dfs(int i, int d){
	int j;
	int deg = 0;
	int p;
	for(j = 0; j < 26; j++)
		if(next[i][j] != -1)
			deg++;
	if(deg >= 2 || size[i]){
		p = cnt++;
		size1[p] = size[i];
		::d[p] = d;
		for(j = 0; j < 26; j++)
			if(next[i][j] != -1)
				s[p].pb(dfs(next[i][j], 1));
	}
	else{
		for(j = 0; j < 26; j++)
			if(next[i][j] != -1)
				return dfs(next[i][j], d+1);
	}
	return p;
}

int main()
{
	#ifdef __FIO
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	int n, K;
	int i, j, k;
	int p;
	scanf("%d%d", &n, &K);
	memset(next, -1, sizeof next);
	cnt = 1;
	for(i = 0; i < n; i++){
		scanf("%s", s1);
		p = 0;
		for(j = 0; s1[j]; j++){
			if(next[p][s1[j]-'a'] == -1)
				next[p][s1[j]-'a'] = cnt++;
			p = next[p][s1[j]-'a'];
		}
		size[p]++;
	}
	cnt = 0;
	dfs(0, 0);
	for(i = cnt-1; i >= 0; i--){
		p = 0;
		f[i][0] = 0;
		for(vector<int>::iterator it = s[i].begin(); it != s[i].end(); it++){
			for(j = 0; j <= p+size1[*it]; j++)
				f1[j] = 0;
			for(j = 0; j <= p; j++)
				for(k = 0; k <= size1[*it]; k++)
					f1[j+k] = max(f1[j+k], f[i][j]+f[*it][k]);
			p += size1[*it];
			for(j = 0; j <= p; j++)
				f[i][j] = f1[j];
		}
		for(j = 1; j <= size1[i]; j++)
			f[i][p+j] = f[i][p];
		size1[i] += p;
		for(j = 1; j <= size1[i]; j++)
			f[i][j] += d[i]*j*(j-1)/2;
	}
	printf("%d\n", f[0][K]);
	return 0;
}