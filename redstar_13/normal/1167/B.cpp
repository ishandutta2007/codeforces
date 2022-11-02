#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define pb push_back
#define y second
#define x first

using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}
typedef vector<int> VI;

int a[]={0, 4, 8, 15, 16, 23, 42};
int ans[10];
int p[11];
int c[11][11];

int get(int x, int y) {
	printf("? %d %d\n", x, y); fflush(stdout);
	int t; scanf("%d", &t);
	c[x][y]=c[y][x]=t;
	return t;
}

inline bool can() {
	for(int i=1; i<=6; i++) {
		for(int j=1; j<=6; j++) if(c[i][j]) {
			if(ans[i]*ans[j]!=c[i][j]) return false;
		}
	}
	return true;
}

int main() {
	
//	get(1, 2);
//	get(2, 3);
//	get(4, 5);
//	get(5, 6);
	
	get(1, 2);
	get(2, 3);
	get(3, 4);
	get(4, 5);
	
	for(int i=1; i<=6; i++) p[i]=i;
	do {
		for(int i=1; i<=6; i++) ans[i]=a[p[i]];
		if(can()) {
			printf("!");
			for(int i=1; i<=6; i++) printf(" %d", ans[i]); puts("");
			fflush(stdout);
			exit(0);
		}
	}
	while(next_permutation(p+1, p+7));
}