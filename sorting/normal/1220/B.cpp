#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 7;

long long a[MAXN][MAXN];

long long sq(long long x){
	long long ret = sqrt(x);

	if(ret * ret != x){
		++ret;
		if(ret * ret != x){
			ret -= 2;
		}
	}

	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> a[i][j];
		}
	}

	for(int i = 0; i < n; ++i){
		if(i > 1){
			cout << sq(a[i][0] * a[i][1] / a[0][1]) << " ";
		}
		else{
			if(i == 1){
				cout << sq(a[i][0] * a[i][2] / a[0][2]) << " ";
			}
			else{
				cout << sq(a[i][n - 1] * a[i][n - 2] / a[n - 1][n - 2]) << " ";
			}
		}
	}
	cout << "\n";

	return 0;
}