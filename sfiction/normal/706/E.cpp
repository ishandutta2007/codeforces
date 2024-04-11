#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E3 + 10;

struct node{
	int val;
	node *right, *down;
};

node a[MAXN][MAXN];

int main(){
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j].val);
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
			a[i][j].right = a[i] + j + 1;
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
			a[i][j].down = a[i + 1] + j;
	for (int qi = 0; qi < q; ++qi){
		int x1, y1, x2, y2, h, w;
		scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &h, &w);
		node *a[2], *b[2];
		a[0] = b[0] = ::a[0];
		for (int i = 1; i < x1; ++i, a[0] = a[0]->down);
		for (int i = 1; i < y1; ++i, a[0] = a[0]->right);
		for (int i = 1; i < x2; ++i, b[0] = b[0]->down);
		for (int i = 1; i < y2; ++i, b[0] = b[0]->right);
		a[1] = a[0], b[1] = b[0];
		for (int i = 0; i < h; ++i, swap(a[0]->right, b[0]->right))
			a[0] = a[0]->down, b[0] = b[0]->down;
		for (int i = 0; i < w; ++i, swap(a[0]->down, b[0]->down))
			a[0] = a[0]->right, b[0] = b[0]->right;
		for (int i = 0; i < w; ++i, swap(a[1]->down, b[1]->down))
			a[1] = a[1]->right, b[1] = b[1]->right;
		for (int i = 0; i < h; ++i, swap(a[1]->right, b[1]->right))
			a[1] = a[1]->down, b[1] = b[1]->down;
			
	}
	for (int i = 1; i <= n; ++i){
		node *t = a[i];
		for (int j = 1; j <= m; ++j){
			t = t->right;
			printf("%d%c", t->val, "\n "[j < m]);
		}
	}
	return 0;
}