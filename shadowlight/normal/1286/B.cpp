#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 2007;

int c[N];
vector <int> gr[N];
int pr[N];
int n;
int root = -1;
int h[N];

void dfs(int v, int p) {
	h[v] = (p == -1 ? 0 : h[p] + 1);
	for (int u : gr[v]) {
		dfs(u, v);
	}
	//cout << v << " " << h[v] << "\n";
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p >> c[i];
		p--;
		if (p == -1) {
			root = i;
		} else {
			gr[p].push_back(i);
		}
		pr[i] = p;
	}
	dfs(root, -1);
	vector <int> vals(N, -1);
	for (int i = 0; i < n; i++) {
		int p = -1;
		for (int v = 0; v < n; v++) {
			if (vals[v] == -1 && !c[v] && (p == -1 || h[p] > h[v])) {
				p = v;
			}
		}
		//cout << p << "\n"; 
		if (p == -1) {
			cout << "NO\n";
			return 0;
		}
		vals[p] = i + 1;
		int now = p;
		while (now != -1) {
			c[now]--;
			now = pr[now];
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		cout << vals[i] << " ";
	}
	cout << "\n";
}