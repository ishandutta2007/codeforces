#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2000 + 10;
int n, mn[N][20][2];
void print() {
	printf("-1\n"); fflush(stdout);
	for(int i=1;i<=n;i++){
		int ans=1e9+7;
		for(int j=0;j<10;j++){
			int b = (i>>j&1) ^ 1;
			ans = min(ans, mn[i][j][b]);
		}
		printf("%d%c", ans," \n"[i==n]);
	}
	fflush(stdout);
}
int main() {
	for(int i=0;i<N;i++)for(int j=0;j<20;j++) mn[i][j][0]=mn[i][j][1]=1e9+7;

	scanf("%d", &n);
	for (int i = 0; i < 10 ; i++) {
		for (int b = 0; b < 2; b ++) {
			vector<int> v;
			for(int x=1;x<=n;x++) if((x>>i&1) == b) v.push_back(x);

			if(v.size()) {
				printf("%d\n", v.size()); fflush(stdout);
				for(int j=0;j<v.size();j++) printf("%d%c", v[j]," \n"[j==(int)v.size()-1]);  fflush(stdout);

				for(int j=1;j<=n;j++) {
					int x; scanf("%d",&x);
					mn[j][i][b] = min(mn[j][i][b], x);
				}
			}
		}
	}

	print();
}