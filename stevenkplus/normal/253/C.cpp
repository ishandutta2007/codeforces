#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

typedef queue<int> qi;

#define add push
const int MAXN = 101;
const int MAXM = 100100;
const int mx[] = {-1, 0, 1, 0}, my[] = {0, 1, 0, -1};
qi rq, cq, dq;

int N;
int ar[MAXN];
bool visited[MAXN][MAXM];

int pop(qi &q) {
	int ans = q.front();
	q.pop();
	return ans;
}
void add(int r, int c, int d) {
	if (r >= 0 && r < N) {
		if (c > ar[r]) c = ar[r];
		if (c < 0) c = 0;
		rq.add(r);
		cq.add(c);
		dq.add(d);
	}
}
void visit(int r, int c, int d) {
	if (visited[r][c]) return;
	visited[r][c] = true;
	for(int i = 0; i < 4; ++i) {
		add(r + mx[i], c + my[i], d + 1);
	}
}	

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar + i);
	}
	int A, B, C, D;
	scanf("%d %d %d %d", &A, &B, &C, &D);
	A--;
	B--;
	C--;
	D--;
	add(A, B, 0);
	int ans;
	while (!rq.empty()) {
		int r = pop(rq), c = pop(cq), d = pop(dq);
		if (r == C && c == D) {
			ans = d;
			break;
		}
		visit(r, c, d);
	}
	printf("%d\n", ans);
	return 0;
}