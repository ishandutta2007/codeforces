#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define ep 1e-9
#define mp make_pair
#define pb push_back
#define ll long long
#pragma comment(linker, "/STACK:1024000000,1024000000")
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}
typedef pair<int, int> pii;
const double pi = 3.1415926535897932384626433832795028841971l;
#define N 202020

int n, q, a[N];
int l[N], r[N];

struct RMQ {
  private:
    int mn[N][20];
  public:
    void build(int *a, int n) {
        for (int i = 1; i <= n; i ++) mn[i][0] = a[i];
        for (int j = 1; (1 << j) <= n; j ++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i ++) {
                mn[i][j] = min(mn[i][j-1], mn[i+(1<<j-1)][j-1]);
            }
        }
    }
    int query(int l, int r) {
        int d = 31 - __builtin_clz(r - l + 1);
        return min(mn[l][d], mn[r-(1<<d)+1][d]);
    }
} T;

vector<int>v[N], w[N];
set<int> S;
int main() {
//    freopen("1.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= q; i ++) l[i] = inf, r[i] = -inf;
	for (int i = 1; i <= n; i ++) {
		chkmin(l[a[i]], i);
		chkmax(r[a[i]], i);
	}
	for (int i = 1; i <= n; i ++) if(a[i] == 0) a[i] = inf;
	T.build(a, n);
	bool flag = 1;
	for (int i = 1; i <= q; i ++) {
		if (l[i] < r[i]) {
			if (T.query(l[i], r[i]) < i) {
				flag = 0;
				break;
			}
		}
	}
	if (!flag) {
		puts("NO");
	}
	else {
		if (l[q] == inf) {
			flag = 0;
			for (int i = 1; i <= n; i ++) if (a[i] == inf) {
				flag = 1;

				a[i] = q;
				break;
			}
			if (!flag) {
				puts("NO");
				return 0;
			}
		}
		for (int i = 1; i <= q; i ++) {
			if (l[i] < inf) v[l[i]].push_back(i);
			if (r[i] > -inf) w[r[i]].push_back(i);
		}
		S.clear();
		for (int i = 1; i <= n; i ++) {
			for (auto j:v[i]) S.insert(j);
			if (!S.empty() && a[i] == inf) a[i] = *S.rbegin();
			for (auto j:w[i]) S.erase(j);
		}
		for (int i = 1; i <= n; i ++) if (a[i] == inf) a[i] = 1;
		puts("YES");
		for (int i = 1; i <= n; i ++) printf("%d ", a[i]);
	}
    return 0;
}