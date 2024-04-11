#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 200010
vector<int> A[N];
int n;
int pr[N];


int main() {
	cin >> n;
	for (int i = 1; i < n; i ++) {
		int x;
		cin >> x;
		x--;
		A[x].pb(i);
		A[i].pb(x);
	}
	memset(pr, -1, sizeof pr);
	pr[0] = 0;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto i : A[x])
			if (pr[i] == -1) {
				pr[i] = x;
				q.push(i);
			}
	}
	vector<int> S;
	int x = n-1;
	for (int x = n-1; x; x = pr[x]) S.pb(x);
	S.pb(0);
	reverse(S.begin(), S.end());
	for (int i = 0; i < (int) S.size(); i ++)
		printf("%d%c", S[i]+1, i == (int) S.size() - 1?'\n': ' ');
	return 0;
}