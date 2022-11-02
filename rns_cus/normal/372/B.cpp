#include<bits/stdc++.h>
using namespace std;

int gas[44][44][44][44], h[100], mn[100][100], tmp[44][44];
char s[100][100];

int sum(int u, int v){
	if(u > v) return 0;
	return tmp[u][v];
}

int n, m, q, a, b, c, d;

int main(){
///	freopen("in.txt", "r", stdin);
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1; i <= n; i ++){
		scanf("%s", s[i] + 1);
	}

	for(int x = 1; x <= n; x ++){
		memset(h, 0, sizeof h);
		for(int xx = x; xx <= n; xx ++){
			for(int j = 1; j <= m; j ++){
				if(s[xx][j] == '0') h[j] ++;
				else h[j] = 0;
			}
//			for(int j = 1; j <= m; j ++) printf("%d ", h[j]); puts("");
			for(int j = 1; j <= m; j ++){
				mn[j][j] = h[j];
				for(int t = j + 1; t <= m; t ++){
					mn[j][t] = min(h[t], mn[j][t-1]);
				}
			}
			for(int d = 0; d < m; d ++){
				for(int y = 1; y + d <= m; y ++){
					tmp[y][y + d] = mn[y][y+d] + sum(y, y + d - 1) + sum(y + 1, y + d) - sum(y + 1, y + d - 1);
					gas[x][xx][y][y+d] = gas[x][xx-1][y][y+d] + tmp[y][y+d];
				//	cout << gas[x][xx][y][y+d] << " ";
				}// cout << endl;
			}
		//	cout << endl;
		}
	}

	while(q --){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("%d\n", gas[a][c][b][d]);
	}
}