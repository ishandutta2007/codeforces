#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <complex>

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3c3c3c3c;
const ll LINF = 1ll*INF*INF*2;

const int N = 101010;
const int M=300;
int n,m,c;
char s[N];
char a[10],b[10];
int t[4][N];

int nxt[N][26];
int dp[M][M][M];
int cur[4];
void update(int x, int y, int z) {
	dp[x][y][z]=INF;
	if(x && dp[x-1][y][z]<INF && nxt[dp[x-1][y][z]+1][t[1][x-1]]) dp[x][y][z]=min(dp[x][y][z], nxt[dp[x-1][y][z]+1][t[1][x-1]]);
	if(y && dp[x][y-1][z]<INF && nxt[dp[x][y-1][z]+1][t[2][y-1]]) dp[x][y][z]=min(dp[x][y][z], nxt[dp[x][y-1][z]+1][t[2][y-1]]);
	if(z && dp[x][y][z-1]<INF && nxt[dp[x][y][z-1]+1][t[3][z-1]]) dp[x][y][z]=min(dp[x][y][z], nxt[dp[x][y][z-1]+1][t[3][z-1]]);

}
int main(void){
	scanf("%d%d", &n, &m);
	scanf("%s", s+1);
	for(int i=n; i>=0; i--) {
		for(int j=0; j<26; j++) {
			nxt[i][j]=nxt[i+1][j];
		}
		if(i) nxt[i][s[i]-'a']=i;
	}
	for(int i=0; i<m; i++) {
		scanf("%s %d", a, &c);
		if(a[0]=='-') {
			cur[c]--;
		} else {
			scanf("%s", b);
			t[c][cur[c]++]=b[0]-'a';
			if(c==1) {
				for(int j=0;j<=cur[2];j++)
					for(int k=0;k<=cur[3];k++)
						update(cur[1], j, k);
			}
			if(c==2) {
				for(int i=0;i<=cur[1];i++)
					for(int k=0;k<=cur[3];k++)
						update(i, cur[2], k);
			}
			if(c==3) {
				for(int i=0;i<=cur[1];i++)
					for(int j=0;j<=cur[2];j++)
						update(i, j, cur[3]);
			}
		}
/*		for(int i=0; i<=cur[1]; i++) {
			for(int j=0; j<=cur[2]; j++) {
				for(int k=0; k<=cur[3]; k++) {
					printf("%d ", dp[i][j][k]);
				}
				cout << endl;
			}
		}*/
		if(dp[cur[1]][cur[2]][cur[3]]<INF) printf("YES\n");
		else printf("NO\n");
		printf("\n");
	}
}