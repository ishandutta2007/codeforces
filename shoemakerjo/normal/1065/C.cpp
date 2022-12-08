#include <bits/stdc++.h>

using namespace std;
#define maxn 200010

int n, k;
int h[maxn];

int curabove = 0;
map<int, int> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ans = 0;
	int minheight = 300000;
	int maxheight = 0;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> h[i];
		minheight = min(minheight, h[i]);
		maxheight = max(maxheight, h[i]);
		mp[h[i]]++;
	}

	int ccost = 0;
	int curactive = 0;

	if (maxheight != minheight) ans++;

	for (int i = maxheight; i >= minheight; i--) {

		if (ccost + curactive > k) {
			ans++;
			ccost = curactive;
		}
		else ccost += curactive;
		curactive += mp[i];

	}
	cout << ans << endl;
}