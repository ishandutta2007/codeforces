#include <bits/stdc++.h>

using namespace std;
#define maxn 100010
#define ll long long
int n, m;
ll l;


int numgroups = 0;
ll nums[maxn];
ll curcost = 0LL;
bool isin[maxn];
int par[maxn];
int sz[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> l;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
		if (nums[i] > l) {
			isin[i] = true;
			numgroups++;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (isin[i] && isin[i-1]) numgroups--;
	}


	int tp;
	int p;
	ll d;
	while (m--) {
		cin >> tp;
		if (tp == 0) {
			cout << numgroups << '\n';
			continue;
		}
		cin >> p >> d;
		if (nums[p] > l) continue;
		nums[p] += d;
		if (nums[p] <= l) continue;
		isin[p] = true;
		numgroups++;
		if (isin[p-1]) numgroups--;
		if (isin[p+1]) numgroups--;

		//combine with previous guys
	}

	cout.flush();
	
}