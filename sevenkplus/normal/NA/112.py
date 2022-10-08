#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 200010
#define P 1000000007

int n;
int v[N];
int a[N];
vector<int> b[N];
int q[N], L;
//int f[N], g[N];

void ff(int x) {
	v[x] = 2;
	for (vector<int>::iterator i = b[x].begin(); i != b[x].end(); i ++)
		if (v[*i] != 2) ff(*i);
	q[L++] = x;
}

int main() {
	cin >> n;
	memset(a, -1, sizeof a);
	for (int i = 0; i < n; i ++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		a[x] = y;
		b[y].pb(x);
	}
	
	int S = 1;
	for (int i = 0; i < n*2; i ++)
		if (!v[i]) {
			int j = i;
			while (!v[j]) {
				v[j] = 1;
				if (a[j] == -1) break;
				j = a[j];
			}
			L = 0;
			ff(j);
			if (a[j] != -1) {
				if (a[j] != j) S = (ll)S*2%P;
				continue;
			}
			S = (ll)S*L%P;
		}
	cout << S << endl;
	return 0;
}