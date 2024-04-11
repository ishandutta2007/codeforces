#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

#define pb push_back
#define sz(x) int((x).size())
#define fi first
#define se second

const int MAXN = 100100;
const int mx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, my[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

vi neighbors[MAXN];
bool vis[MAXN];

int ans;
int target;

queue<int> nq, dq;
void visit(int n, int d) {
	if (vis[n]) {
		return;
	}
	vis[n] = true;
	if (n == target) {
		ans = d;
	}
	vi &v = neighbors[n];
	int z = sz(v);
	for (int i = 0; i < z; ++i) {
		nq.push(v[i]);
		dq.push(d + 1);
	}
}

int X0, Y0, X1, Y1;
int N;

int xs[MAXN], ys[MAXN];
map<pii, int> mymap;

int main() {
	scanf("%d %d %d %d", &X0, &Y0, &X1, &Y1);
	scanf("%d", &N);
	int j = 1;
	for(int i = 0; i < N; ++i) {
		int r, a, b;
		scanf("%d %d %d",&r, &a, &b);
		for(int x = a; x <= b; ++x) {
			pii p(r, x);
			if (!mymap[p]) {
				mymap[p] = j;
				xs[j] = r;
				ys[j] = x;
				j++;
			}
		}
	}
	for(int i = 1; i < j; ++i) {
		for(int d = 0; d < 8; ++d) {
			int a = xs[i] + mx[d];
			int b = ys[i] + my[d];
			int k = mymap[pii(a, b)];
			if (k) {
				neighbors[i].pb(k);
			}
		}
	}
	ans = -1;
	target = mymap[pii(X1, Y1)];
	int start = mymap[pii(X0, Y0)];
	visit(start, 0);
	while (!nq.empty() && ans == -1) {
		int n = nq.front();
		nq.pop();
		int d = dq.front();
		dq.pop();
		visit(n, d);
	}
	printf("%d\n", ans);
	return 0;
}