#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
const int N = 1e5, X[4] = {1, -1, 0, 0}, Y[4] = {0, 0, 1, -1};

int t, n, m, lx, rx, ly, ry;
int ans[N], now;
vector< vector<bool> > seat;

bool legal(int x, int y){
	return x >= 0 && y >= 0 && x < n && y < m;
}

struct coordinate{
	int x, y;
	coordinate(int _x, int _y) : x(_x), y(_y){}
};
vector<coordinate> a, b;

int main(){
	scanf("%d", &t);
	while(t--){
		b.clear();
		scanf("%d%d", &n, &m);
		seat = vector< vector<bool> >(n, vector<bool>(m, false));
		ans[0] = n / 2 + m / 2;
		if(n & 1) lx = rx = n / 2;
		else lx = n / 2 - 1, rx = n / 2;
		if(m & 1) ly = ry = m / 2;
		else ly = m / 2 - 1, ry = m / 2;
		now = (rx - lx + 1) * (ry - ly + 1);
		for(int i = 1; i < now; i++)
			ans[i] = ans[0];
		for(int i = lx; i <= rx; i++)
			for(int j = ly; j <= ry; j++){
				b.push_back(coordinate(i, j));
				seat[i][j] = true;
			}
		while(!b.empty()){
			a = vector<coordinate>();
			swap(a, b);
			for(coordinate pos : a){
				for(int i = 0; i < 4; i++){
					int x = pos.x + X[i];
					int y = pos.y + Y[i];
					if(legal(x, y) && !seat[x][y]){
						seat[x][y] = true;
						b.push_back(coordinate(x, y));
					}
				}
			}
			int last = now;
			now += b.size();
			for(int i = last; i < now; i++)
				ans[i] = ans[last - 1] + 1;
		}
		for(int i = 0; i < n * m; i++)
			printf("%d ", ans[i]);
		putchar('\n');
	}
	return 0;
}