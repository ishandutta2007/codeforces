#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
struct edge { int v, w; };
const int INF = INT_MAX / 2;
const int MOD = 1e9 + 7;

int main() {
	int N; cin >> N;
	vector<int> a(N);
	for (int l = 0; l <= N; l++)
		for (int r = l + 1; r <= N; r++)
			for (int i = l; i < r; i++)
				a[i]++;
	int ma = 0;
	rep(i, N) ma = max(ma, a[i]);
	cout << ma << endl;
}