#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int mat[N][N];
int n, k;
vector<tuple<int, int, int>> ans;

int x, y;

void rot(){
	
	int i = x, j = y, tmp = 2*n - 1;
	int ay = x == 2 ? 1 : -1;
	int a, b;
	while(tmp--){
		assert(mat[i][j] == 0);
		a = i, b = j + ay;
		if(b == n+1){
			b = n;
			ay = -1;
			a = 3;
		}
		else if(b == 0){
			a = 2;
			b = 1;
			ay = 1;
		}

		if(mat[a][b]){
			ans.emplace_back(mat[a][b], i, j);
			swap(mat[a][b], mat[i][j]);
		}

		i = a, j = b;
	}
	x = i, y = j;
}

int mv(){
	int tmp = 0;
	for(int j = 1; j <= n; j++) if(mat[2][j]){
		if(mat[2][j] == mat[1][j]){	
			ans.emplace_back(mat[2][j], 1, j);
			mat[2][j] = 0;
			tmp++;
		}
	}

	for(int j = 1; j <= n; j++) if(mat[3][j]){
		if(mat[3][j] == mat[4][j]){	
			ans.emplace_back(mat[3][j], 4, j);
			mat[3][j] = 0;
			tmp++;
		}
	}
	return tmp;
}

int main(){
	scanf("%d %d", &n, &k);

	for(int i = 1; i <= 4; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &mat[i][j]);
	
	int s = mv();

	x = y = -1;
	for(int j = 1; j <= n; j++) if(!mat[3][j]){
		x = 3, y = j;
	}

	for(int j = 1; j <= n; j++) if(!mat[2][j]){
		x = 2, y = j;
	}

	if(x == -1) return printf("-1\n"), 0;

	while(s < k){
		rot();
		s += mv();
	}

	printf("%d\n", (int)ans.size());

	for(auto w : ans){
		int a, b, c;
		tie(a, b, c) = w;
		printf("%d %d %d\n", a, b, c);
	}

}