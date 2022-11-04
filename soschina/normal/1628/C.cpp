#include <cstdio>
using namespace std;
const int N = 1000, X[4] = {1, -1, 0, 0}, Y[4] = {0, 0, 1, -1};

int t, n, a[N][N], ans;
bool vis[N][N];

bool legal(int x, int y){
	return x >= 0 && y >= 0 && x < n && y < n;
}

int main(){
	scanf("%d", &t);
	while(t--){
		ans = 0;
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				scanf("%d", &a[i][j]);
				vis[i][j] = false;
			}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				bool paint = true;
				for(int k = 0; k < 4 && paint; k++){
					int x = i + X[k];
					int y = j + Y[k];
					if(legal(x, y) && vis[x][y])
						paint = false;
				}
				if(paint){
					ans ^= a[i][j];
					for(int k = 0; k < 4 && paint; k++){
						int x = i + X[k];
						int y = j + Y[k];
						if(legal(x, y))
							vis[x][y] = true;
					}
				}
			}
		printf("%d\n", ans);
	}
	return 0;
}