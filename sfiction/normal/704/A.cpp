#include <cstdio>

const int MAXN = 3E5 + 10, MAXQ = 3E5 + 10;

int rec[MAXN], res[MAXN];
int a[MAXQ];

int main(){
	int n, q;
	scanf("%d%d", &n, &q);
	int type, x, tail = 0;
	int last = 0, tot = 0;
	for (int qi = 1; qi <= q; ++qi){
		scanf("%d%d", &type, &x);
		switch (type){
		case 1:
			a[++tail] = x;
			++res[x];
			++tot;
			break;
		case 2:
			tot -= res[x];
			res[x] = 0;
			rec[x] = tail;
			break;
		case 3:
			for (int i = last + 1; i <= x && i <= tail; ++i)
				if (i > rec[a[i]]){
					--res[a[i]];
					--tot;
				}
			if (last < x)
				last = x;
			break;
		}
		printf("%d\n", tot);
	}
	return 0;
}