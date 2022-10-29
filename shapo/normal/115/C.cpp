#include <cstdio>

#define MAXN 500100

using namespace std;

int make_row[MAXN], make_col[MAXN];

int main () {
	int n, m, cur_c, row, col;
	char cur_ch;
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			scanf (" %c", &cur_ch);
			if (cur_ch != '.') {
				cur_c = cur_ch - '1';
				row = cur_c / 2 + 1;
				col = (!cur_c || cur_c == 3) ? 1 : 2;
				if (j & 1) row = 3 - row;
				if (i & 1) col = 3 - col;
				if (make_row[i] && make_row[i] != row) {
					printf ("0\n");
					return 0;
				}
				make_row[i] = row;
				if (make_col[j] && make_col[j] != col) {
					printf ("0\n");
					return 0;
				}
				make_col[j] = col;
			}
		}
	int num = 0;
	for (int i = 0; i < n; ++i)
		num += !make_row[i];
	for (int j = 0; j < m; ++j)
		num += !make_col[j];
	int res = 1;
	for (int i = 1; i <= num; ++i)
		res = (res * 2) % 1000003;
	printf("%d\n", res);
	return 0;
}