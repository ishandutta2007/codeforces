// m(_ _)m
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VII;

char w[105][25];
int c[105];
int a[2][105], b[2][105];

int d[105][105];

int main()
{
#ifdef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, t, k;
	scanf("%d%d", &n, &t);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d%d", &a[0][i], &b[0][i], &a[1][i], &b[1][i]);
	scanf("%d", &k);
	for(int i=0;i<k;i++) {
		scanf("%s", w[i]);
		scanf("%d", &c[i]);
	}
	int jmp[105]={}, fil=k;
	int nowk=0, player=0, team=0;
	vector<int> slv[105];
	while(fil>0) {
		//fprintf(stderr, "%d\n", fil);
		if(++team > n) { team = 1; player^=1;}
		int rmt=t;
		while(rmt>0 && fil>0) {
			//fprintf(stderr, "here %d %d %d %d\n", rmt, fil, player, team);
			while(jmp[nowk]) { ++nowk; if(nowk==k) nowk=0; }
			int v = max(1, c[nowk]-(a[player][team]+b[player^1][team])-d[team][nowk]);
			if (v <= rmt) {
				rmt -= v;
				slv[team].push_back(nowk);
				jmp[nowk] = 1;
				--fil;
			} else {
				d[team][nowk] += rmt;
				rmt = 0;
			}
		}
		if(++nowk==k) nowk=0;
	}
	for(int i=1;i<=n;i++) {
		printf("%d", (int)slv[i].size());
		for(int j=0;j<(int)slv[i].size();j++)
			printf(" %s", w[slv[i][j]]);
		puts("");
	}
	return 0;
}