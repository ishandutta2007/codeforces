#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)

#define N 100010

int n, a[N], b[N];
vector <int> v[N];
int sz, id[N];
bool vis[N];

bool cmp(int x, int y) {
	return a[x] < a[y];
}

int main() {
    scanf("%d", &n);
    f1(i, 1, n) scanf("%d", &a[i]), id[i] = i;
    sort(id + 1, id + n + 1, cmp);
    f1(i, 1, n) b[id[i]] = i;
    f1(i, 1, n) if (!vis[i]) {
        sz ++;
        while (!vis[i]) {
            vis[i] = 1;
            v[sz].pb(i);
            i = b[i];
        }
    }
    printf("%d\n", sz);
    f1(i, 1, sz) {
    	printf("%d ", v[i].size());
		f0(j, 0, v[i].size()) printf("%d ", v[i][j]);
		puts("");
    }
	return 0;
}