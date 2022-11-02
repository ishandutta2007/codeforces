#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define x first
#define y second
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)

typedef pair <int, int> pii;

#define N 100005

int n, m;
int a[N], b[N];
vector <int> v[N];

priority_queue <pii> pq;

int main() {
    scanf("%d %d", &n, &m);
    int x, y;
    while (m --) {
		scanf("%d %d", &x, &y);
        a[x] --;
        v[y].pb(x);
    }
    f1(i, 1, n) pq.push(pii(a[i], i));
    f1(i, 1, n) {
        pii rpt = pq.top(); pq.pop();
        b[rpt.y] = n - i + 1;
        f0(j, 0, v[rpt.y].size()) {
            x = v[rpt.y][j];
            a[x] ++;
            pq.push(pii(a[x], x));
        }
    }
    f1(i, 1, n) printf("%d ", b[i]);
	return 0;
}