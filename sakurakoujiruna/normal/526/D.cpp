#include <bits/stdc++.h>
using namespace std;

const int N = 1011111;
using ll = long long;
char c[N];
int p[N];

int st[N][23];

int main() {
	//ios :: sync_with_stdio(false);
	int n, k; cin >> n >> k;
	scanf("%s", c + 1);
	p[0] = p[1] = 0; int t = 0;
	for(int i = 2; i <= n; i ++) {
		while(t != 0 && c[i] != c[t + 1]) t = p[t];
		if(c[i] == c[t + 1]) t ++;
		p[i] = t;
		//cout << i << ' ' << p[i] << '\n';
	}
	for(int i = 0; i <= n; i ++) st[i][0] = p[i];
	for(int k = 1; k < 23; k ++)
		for(int i = 0; i <= n; i ++)
			st[i][k] = st[st[i][k - 1]][k - 1];

	for(int i = 1; i <= n; i ++) {
		int low = (ll(k - 1) * i + k - 1) / k;
		int high = ll(k) * i / (k + 1);
		int t = i;
		for(int i = 22; i >= 0; i --)
			if(st[t][i] > high) t = st[t][i];
		t = p[t];

		if(t >= low && t <= high)
			printf("1");
		else
			printf("0");
	}
	puts("");
	return 0;
}