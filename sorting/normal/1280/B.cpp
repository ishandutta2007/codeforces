#include <bits/stdc++.h>

using namespace std;

const int MAXN = 61;

string s[MAXN];
int row[MAXN], col[MAXN];
int sum[MAXN][MAXN];

int sum_rect(int x1, int y1, int x2, int y2){
	if(x1 > x2)
		return 0;
	if(y1 > y2)
		return 0;

	if(x1 == 0){
		if(y1 == 0)
			return sum[x2][y2];
		else
			return sum[x2][y2] - sum[x2][y1 - 1];
	}
	else{
		if(y1 == 0)
			return sum[x2][y2] - sum[x1 - 1][y2];
	}

	return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

void solve(){
	int r, c;
	cin >> r >> c;

	for(int i = 0; i < r; ++i)
		cin >> s[i];

	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			sum[i][j] = (s[i][j] == 'P');
		}
	}

	for(int i = 0; i < r; ++i){
		for(int j = 1; j < c; ++j){
			sum[i][j] += sum[i][j - 1];
		}
	}

	for(int j = 0; j < c; ++j){
		for(int i = 1; i < r; ++i){
			sum[i][j] += sum[i - 1][j];
		}
	}

	int cnt = 0, ans = 5;
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			if(s[i][j] == 'A'){
				++cnt;

				int curr1 = (bool)sum_rect(i + 1, j, r - 1, j) + (bool)sum_rect(0, j, i - 1, j) + (bool)sum_rect(0, 0, r - 1, j - 1) + (bool)sum_rect(0, j + 1, r - 1, c - 1);
				int curr2 = (bool)sum_rect(i, j + 1, i, c - 1) + (bool)sum_rect(i, 0, i, j - 1) + (bool)sum_rect(0, 0, i - 1, c - 1) + (bool)sum_rect(i + 1, 0, r - 1, c - 1);

				ans = min(ans, min(curr1, curr2));
			}
		}
	}

	if(!cnt){
		cout << "MORTAL\n";
		return;
	}
	if(cnt == r * c){
		cout << "0\n";
		return;
	}

	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();
}