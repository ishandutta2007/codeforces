#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int n, m;

int dijk(bool e[410][410])
{
    vi d(n, 1000);

    d[0] = 0;
    queue<int> que;
    que.push(0);

    while (!que.empty()) {
	int v = que.front(); que.pop();
	rep(to, n) if (e[v][to] && d[to] == 1000) {
	    d[to] = d[v] + 1;
	    que.push(to);
	}
    }
    return d[n - 1];
}

bool e1[410][410], e2[410][410];

int main() {
    cin >> n >> m;
    
    rep(i, n) rep(j, n) e2[i][j] = 1;

    rep(i, m) {
	int a, b;
	cin >> a >> b;
	--a; --b;
	e1[a][b] = e1[b][a] = 1;
	e2[a][b] = e2[b][a] = 0;
    }

    int a = dijk(e1);
    int b = dijk(e2);
    if (a == 1000 || b == 1000) {
	puts("-1");
    } else cout << max(a, b) << endl;
    return 0;
}