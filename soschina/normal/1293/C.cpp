#include <cstdio>
using namespace std;
const int MAXN = 2e5 + 1;

bool map[3][MAXN];
int n, q, cnt, x, y;

int main(){
	scanf("%d%d", &n, &q);
	while(q--){
		scanf("%d%d", &x, &y);
		map[x][y] ^= 1;
		for(int i = -1; i <= 1; i++)
			if(y + i > 0 && y + i <= n && map[x ^ 3][y + i])
				cnt += map[x][y] ? 1 : -1;
		printf("%s\n", cnt ? "No" : "Yes");
	}
	return 0;
}