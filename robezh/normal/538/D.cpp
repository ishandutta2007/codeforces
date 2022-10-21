#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

typedef pair<int, int> P;

int n;
char mov[55][55];
char res[105][105];
bool good[55][55];
vector<P> V;


bool in_bound(int x, int y){
	return x < n && x >= 0 && y < n && y >= 0;
}

bool check(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(mov[i][j] == 'x' && !good[i][j]) return false;
		}
	}
	return true;
}

void print_check(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d", good[i][j]);
		}
		printf("\n");
	}
}

char get_move(int dx, int dy){
	char c = '?';
	for(int i = 0; i < V.size(); i++){
		int x = V[i].first, y = V[i].second;
		if(!in_bound(x + dx, y + dy)) continue;
		if(c == '?' && mov[x + dx][y + dy] != 'o') c = mov[x+dx][y+dy];
		else if(c != '?' && mov[x + dx][y + dy] != 'o' && mov[x + dx][y + dy] != c) return '.';
	}
	for(int i = 0; i < V.size(); i++){
		int x = V[i].first, y = V[i].second;
		if(in_bound(x + dx, y + dy)) good[x + dx][y + dy] = true;
	}
	if(c == '?') return '.';
	return c;
	
}

int main(){
	scanf("%d", &n);
	getchar();
	for(int i = 0; i < n; i++){
		scanf("%s", mov[i]);
		fill(good[i], good[i] + n, false);
	}
	good[n-1][n-1] = true;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(mov[i][j] == 'o') V.push_back(P(i,j));
		}
	}
	res[n-1][n-1] = 'o';
	for(int i = 0; i < 2 * n - 1; i++){
		for(int j = 0; j < 2 * n - 1; j++){
			if(i != n-1 || j != n-1){
				char c = get_move(i - n + 1, j - n + 1);
				//if(c == 'e') return !printf("NO");
				res[i][j] = c;
			}
		}
	}
	
	//print_check();
	if(!check()) return !printf("NO");
	printf("YES\n");
	for(int i = 0; i < 2 * n - 1; i++){
		printf("%s\n", res[i]);
	}
}