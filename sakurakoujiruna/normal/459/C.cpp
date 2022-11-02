#include <bits/stdc++.h>
using namespace std;

const int N = 1011;

int ans[N][N];

int main() {
	//ios :: sync_with_stdio(false);
	int n, k, d;
	cin >> n >> k >> d;
	if(k == 1) {
		if(n > 1) cout << "-1\n";
		else for(int i = 0; i < d; i ++) cout << "1\n";
		return 0;
	}
	bool flag = true;
	for(int j = 0; j < n; j ++)
		for(int i = 0, w = 1; w <= j; w *= k, i ++) {
			if(i == d)
				flag = false;
			ans[i][j] = j / w % k;
		}
	if(!flag) cout << "-1\n";
	else {
		for(int i = 0; i < d; i ++) {
			for(int j = 0; j < n; j ++)
				printf("%d ", ans[i][j] + 1);
			puts("");
		}
	}
	return 0;
}