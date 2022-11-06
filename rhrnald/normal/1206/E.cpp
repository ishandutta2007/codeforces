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

const int N = 100;
int n,m,rep;

int ans[N][N];
int _ans(pii x) {return ans[x.first][x.second];}
vector<pii> v;
void fill(int x, int y, int a, int b) {
	if(ans[x][y]>=0 && ans[a][b]>=0) return;
	printf("? %d %d %d %d\n", x, y, a, b); fflush(stdout);
	scanf("%d", &rep);
	if(ans[x][y]<0) {
		if(rep) ans[x][y]=ans[a][b];
		else ans[x][y]=1-ans[a][b];
	} else {
		if(rep) ans[a][b]=ans[x][y];
		else ans[a][b]=1-ans[x][y];
	}
}
void fillA(int x, int y) {
	for(int i=y+2; i<=n; i+=2) fill(x,i-2,x,i);
	for(int i=x+2; i<=n; i+=2)
		for(int j=y; j<=n; j+=2)
			fill(i-2,j,i,j);

	for(int i=x; i<=n-2; i+=2)
		for(int j=y; j<=n-2; j+=2)
			fill(i,j,i+1,j+1);
}
int main(void){
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) ans[i][j]=-1;
	ans[1][1]=1; ans[n][n]=0;
	
	fillA(1,1);
	
	for(int i=1; i<=n; i++) v.push_back({1, i});
	for(int i=2; i<=n; i++) v.push_back({i, n});

	int f;
	for(int i=0; i<sz(v)-4; i+=2) {
		if(_ans(v[i]) != _ans(v[i+4])) {
			int a=_ans(v[i]), b=_ans(v[i+2]), c=_ans(v[i+4]);
			printf("? %d %d %d %d\n", v[i+1].first, v[i+1].second, v[i+3].first, v[i+3].second); fflush(stdout);
			scanf("%d", &rep);
			if(rep) {
				if(a==b) {
					printf("? %d %d %d %d\n", v[i].first, v[i].second, v[i+3].first, v[i+3].second); fflush(stdout);
					scanf("%d", &rep);
					if(rep) {
						ans[v[i+1].first][v[i+1].second]=b;
						ans[v[i+3].first][v[i+3].second]=b;
					} else {
						ans[v[i+1].first][v[i+1].second]=1-b;
						ans[v[i+3].first][v[i+3].second]=1-b;
					}
				} else {
					printf("? %d %d %d %d\n", v[i+1].first, v[i+1].second, v[i+4].first, v[i+4].second); fflush(stdout);
					scanf("%d", &rep);
					if(rep) {
						ans[v[i+1].first][v[i+1].second]=b;
						ans[v[i+3].first][v[i+3].second]=b;
					} else {
						ans[v[i+1].first][v[i+1].second]=1-b;
						ans[v[i+3].first][v[i+3].second]=1-b;
					}					
				}
			} else {
				if(a==b) {
					printf("? %d %d %d %d\n", v[i+1].first, v[i+1].second, v[i+4].first, v[i+4].second); fflush(stdout);
					scanf("%d", &rep);
					if(rep) {
						ans[v[i+1].first][v[i+1].second]=c;
						ans[v[i+3].first][v[i+3].second]=b;
					} else {
						ans[v[i+1].first][v[i+1].second]=b;
						ans[v[i+3].first][v[i+3].second]=c;
					}
				} else {
					printf("? %d %d %d %d\n", v[i].first, v[i].second, v[i+3].first, v[i+3].second); fflush(stdout);
					scanf("%d", &rep);
					if(rep) {
						ans[v[i+1].first][v[i+1].second]=b;
						ans[v[i+3].first][v[i+3].second]=a;
					} else {
						ans[v[i+1].first][v[i+1].second]=a;
						ans[v[i+3].first][v[i+3].second]=b;
					}
				}
			}
			f=i+1;
			break;
		}
	}

	for(int i=f; i>=3; i-=2) fill(v[i-2].first, v[i-2].second, v[i].first, v[i].second);
	for(int i=f+4; i<sz(v); i+=2) fill(v[i-2].first, v[i-2].second, v[i].first, v[i].second);
	fillA(1,2);
	for(int i=2; i<=n; i+=2) fill(i, 1, i, 3);
	
	printf("!\n");
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) printf("%d", ans[i][j]);
		printf("\n");
	}
}