#include <cstdio>

#define maxn 64

int m, n, num = 0, res;
int pp[maxn][maxn];
int used[maxn][maxn];
char cur;

void input_data(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j){
			scanf(" %c", &cur);
			pp[i][j] = (cur == '.') ? 0 : 1;
			num += pp[i][j];
		}
}

void DFS(const int &dx, const int &dy, const int &size){
	used[dx][dy] = size;
	if(dy > 0 && pp[dx][dy - 1] && !used[dx][dy - 1])DFS(dx, dy - 1, size);
	if(dy < m - 1 && pp[dx][dy + 1] && !used[dx][dy + 1])DFS(dx, dy + 1, size);
	if(dx > 0 && pp[dx - 1][dy] && !used[dx - 1][dy])DFS(dx - 1, dy, size);
	if(dx < n - 1 && pp[dx + 1][dy] && !used[dx + 1][dy])DFS(dx + 1, dy, size);
}

bool DFS1(){
	for(int i = 0; i < maxn; ++i)
		for(int j = 0; j < maxn; ++j)
			used[i][j] = 0;
	int col = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(pp[i][j] && !used[i][j])DFS(i, j, ++col);
	return(col < 2);
}

void o_n(const int &xx){printf("%d\n", xx);}

int calc(){
	res = -1;
	if(num > 2){
		res = 1;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j)
				if(pp[i][j]){
					pp[i][j] = 0;
					if(!DFS1())return 0;
					pp[i][j] = 1;
				}
		res = 2;
	}
	return 0;
}

int main(){
	input_data();
	calc();
	o_n(res);	
	return 0;
}