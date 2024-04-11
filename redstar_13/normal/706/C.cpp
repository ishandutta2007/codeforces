
#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

typedef pair<int, int> pii;
typedef long long INT;

template <class T> inline void smin(T &a, T b) {if (a>b) a=b;}
template <class T> inline void smax(T &a, T b) {if (a<b) a=b;}

#define NN 111111

INT best[NN][2], c[NN];
char s[2][NN], pre[2][NN];

int main() {
	
	int N, i, j, k;

	scanf("%d", &N);
	for (i=0; i<N; i++) scanf("%I64d", c+i);
	memset(best, 0x3f, sizeof(best));
	memset(s, 0, sizeof(s));
	
	for (i=0; i<N; i++) {
		scanf("%s", s[0]);
		strcpy(s[1], s[0]);
		
		int len=strlen(s[0]);
		reverse(s[1], s[1]+len);

		if (i==0) {
			best[i][0]=0;
			best[i][1]=c[i];
		} else {
			for (j=0; j<2; j++) {
				for (k=0; k<2; k++) {
					if (strcmp(pre[k], s[j])<=0) {
						if (j==0) smin(best[i][j], best[i-1][k]);
						else smin(best[i][j], best[i-1][k]+c[i]);
					}
				}
			}
		}
		
		strcpy(pre[0], s[0]);
		strcpy(pre[1], s[1]);
	}
	
	INT ans=min(best[N-1][0], best[N-1][1]);
	if (ans>0x3f3f3f3f3f3f3f3fLL-10) puts("-1");
	else printf("%I64d\n", ans);
	
	return 0;
}