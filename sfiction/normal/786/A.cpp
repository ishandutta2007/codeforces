#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E4 + 10;

int f[2][MAXN];

int main(){
	int n, k[2];
	scanf("%d", &n);
	vector<int> a[2];
	scanf("%d", k);
	a[0] = vector<int>(k[0]);
	for (int i = 0; i < k[0]; ++i)
		scanf("%d", &a[0][i]);
	scanf("%d", k + 1);
	a[1] = vector<int>(k[1]);
	for (int i = 0; i < k[1]; ++i)
		scanf("%d", &a[1][i]);

	fill_n(f[0], n, -k[0]);
	fill_n(f[1], n, -k[1]);

	f[0][0] = f[1][0] = 0;
	queue<int> Q;
	Q.push(0);
	Q.push(1);
	while (!Q.empty()){
		int p = Q.front() & 1, u = Q.front() >> 1;
		Q.pop();

		p ^= 1;
		if (f[!p][u]){
			for (int i = 0; i < a[p].size(); ++i){
				int v = (u + n - a[p][i]) % n;
				if (f[p][v] < 0 && ++f[p][v] == 0)
					Q.push(v << 1 | p);
			}
		}
		else{
			for (int i = 0; i < a[p].size(); ++i){
				int v = (u + n - a[p][i]) % n;
				if (f[p][v] < 0){
					f[p][v] = 1;
					Q.push(v << 1 | p);
				}
			}
		}
	}

	for (int i = 0; i < 2; ++i)
		for (int j = 1; j < n; ++j)
			printf("%s%c", f[i][j] == 0 ? "Lose" : f[i][j] == 1 ? "Win" : "Loop", "\n "[j + 1 < n]);
	return 0;
}