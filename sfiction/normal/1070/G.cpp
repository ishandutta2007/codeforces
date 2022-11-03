#include <bits/stdc++.h>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1E2 + 10, M = N;

pii a[M];
int mark[N];
int f[N], g[N];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i){
		scanf("%d%d", &a[i].st, &a[i].nd);
		mark[a[i].st] = i + 1;
	}
	sort(a, a + m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", f + i);

	vector<int> lst[2];
	for (int l = 1; l <= n; ++l){
		for (int p = 0; p < 2; ++p){
			lst[0].clear();
			lst[1].clear();
			copy_n(f + 1, n, g + 1);
			int L = l, R = l;
			if (p)
				++R;
			else
				--L;
			
//			printf("%d %d\n", L, R);
			while (a[0].st <= L){
				int x = -1;
				for (int i = 0; i < m && a[i].st <= L; ++i){
					int t = a[i].nd, flag = true;
//					printf("%d %d %d\n", i, a[i].st, a[i].nd);
					for (int j = a[i].st; j <= L; ++j)
						flag &= (t += g[j]) >= 0;
					if (flag){
						x = i;
						break;
					}
				}
				if (x == -1)
					break;
				for (int i = x; i < m && a[i].st <= L; ++i)
					lst[0].push_back(a[i].st);
				fill(g + a[x].st, g + L + 1, 0);
				L = a[x].st - 1;

//				printf("x = %d, L = %d\n", x, L);
			}
			while (R <= a[m - 1].st){
				int x = -1;
				for (int i = m - 1; i >= 0 && a[i].st >= R; --i){
					int t = a[i].nd, flag = true;
//					printf("%d %d %d\n", i, a[i].st, a[i].nd);
					for (int j = a[i].st; j >= R; --j)
						flag &= (t += g[j]) >= 0;
					if (flag){
						x = i;
						break;
					}
				}
				if (x == -1)
					break;
				for (int i = x; i >= 0 && a[i].st >= R; --i)
					lst[1].push_back(a[i].st);
				fill(g + R, g + a[x].st + 1, 0);
				R = a[x].st + 1;

//				printf("x = %d, R = %d\n", x, R);
			}
			if (g[l] == 0 && L < a[0].st && R > a[m - 1].st){
				printf("%d\n", l);
				if (!p)
					lst[0].swap(lst[1]);
				for (auto &x: lst[1])
					lst[0].push_back(x);
				for (int i = 0; i < m; ++i)
					printf("%d%c", mark[lst[0][i]], "\n "[i + 1 < m]);
				return 0;
			}
		}
	}
	puts("-1");
	return 0;
}