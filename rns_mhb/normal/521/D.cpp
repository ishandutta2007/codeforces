#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define x first
#define y second
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)

typedef pair <int, int> pii;
typedef pair <double, int> pdi;

#define N 100005

int n, m, k;
int a[N];
int b[N], c[N], d[N];

vector <pdi> v;
vector <pii> u[N];

bool cmp(pdi x, pdi y) {
    return d[x.y] < d[y.y];
}

int main() {
	scanf("%d %d %d", &k, &n, &m);
	f1(i, 1, k) scanf("%d", &a[i]);
	int type, x, y;
	f1(i, 1, n) {
        scanf("%d %d %d", &type, &x, &y);
        d[i] = type;
        if (type == 1 && b[x] < y) {
            b[x] = y;
            c[x] = i;
        }
        else if (type == 2) u[x].pb(pii(y, i));
        else if (type == 3) v.pb(pdi(y, i));
	}
	f1(i, 1, k) {
		if (b[i] > a[i]) u[i].pb(pii(b[i]-a[i], c[i]));
        sort(u[i].begin(), u[i].end(), greater <pii> () );
        ll now = a[i];
        for (auto x : u[i]) {
            v.pb(pdi(1.0*(now+x.x)/now, x.y));
            now += x.x;
        }
	}
    sort(v.begin(), v.end(), greater <pdi> ());
    int sz = min((int)(v.size()), m);
    v.resize(sz);
    sort(v.begin(), v.end(), cmp);
    printf("%d\n", sz);
    f0(i, 0, sz) cout << v[i].y << " "; cout << endl;
	return 0;
}