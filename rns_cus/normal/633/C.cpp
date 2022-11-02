#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100100;
const int maxm = 100010;
char w[maxn][1010];
int tr[maxm*10][27], vis[maxm*10];
int m, n, cnt;
int f[maxn];
char s[maxn];
int main() {
	scanf("%d%s",&m,s);
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) {
		scanf("%s",w[i]);
		int t = 0;
		for(int j = 0; w[i][j]; j++) {
			int x;
			if(w[i][j] >= 'A' && w[i][j] <= 'Z') x = w[i][j] - 'A';
			else x = w[i][j] - 'a';
			if(!tr[t][x]) tr[t][x] = ++cnt;
			t = tr[t][x];
		}
		vis[t] = i;
	}
	f[m] = -1;
	for(int i = m-1; i >= 0; i--) if(f[i+1]) {
		int t = 0;
		for(int j = i; j >= 0 && i-j<=1000; j--) {
			int x = s[j] - 'a';
			if(!tr[t][x]) break;
			t = tr[t][x];
			if(vis[t]) f[j] = vis[t];
		}
	}


	for(int i = 0; i < m; i+=strlen(w[f[i]])) {
		printf("%s ",w[f[i]]);
	}

	return 0;
}