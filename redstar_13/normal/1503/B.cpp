#include<bits/stdc++.h>

using namespace std;
using INT = long long;

#define beyond(u, v) ((u<1) | (v<1) | (u>n) | (v>n))
const int NN = 111;
int a[NN][NN];
int n;
int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};

int ask(int c, int u, int v) {
	a[u][v]=c;
	printf("%d %d %d\n", c, u, v); fflush(stdout);
	return 1;
}

int find(int b, int s) {
	int f=1;
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) if((i+j&1) == b and !a[i][j]) {
		f=0;
		break;
	}
	if(f==0) return 0;
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) if(a[i][j]==0) {
		for(int r=1; r<=3; r++) if(r != s) {
			int ans=1;
			for(int k=0; k<4; k++) {
				int ni=i+di[k];
				int nj=j+dj[k];
				if(beyond(ni, nj)) continue;
				if(a[ni][nj]==r) ans=0;
			}
			if(ans) return ask(r,i,j);
		}
	}
}

int solve() {
	int x;
	cin >> x;
	for(int j=0; j<2; j++) {
		if(find(j, x)) {
			return 0;
		}
	}
	
	int c=(x==a[1][1]);
	int tmp=0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) if((i+j&1) == c and a[i][j]) tmp = a[i][j];
	}
	if(tmp==0) tmp=(x==1?2:1);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) if((i+j&1) == c and !a[i][j]) {
			ask(tmp, i, j);
			return 1;
		}
	}
}

int main() {
	
	cin >> n;
	int m = n * n;
	while(m--) solve();
}