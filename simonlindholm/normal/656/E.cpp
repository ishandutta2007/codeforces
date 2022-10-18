#include <bits/stdc++.h>
using namespace std;

template<class F>
void loop(int N, F f) {
	int i = 0;
loopa:
	f(i);
	i++;
	goto *(i < N ? &&loopa : &&breaka);
breaka:;
}

int main() {
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	vector<vector<int> > mat(N, vector<int>(N));
	loop(N, [&](int i){
		loop(N, [&](int j){
			cin >> mat[i][j];
		});
	});
	loop(N, [&](int k) {
		loop(N, [&](int i) {
			loop(N, [&](int j) {
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			});
		});
	});
	int res = 0;
	loop(N, [&](int i) {
		loop(N, [&](int j) {
			res = max(res, mat[i][j]);
		});
	});
	cout << res << endl;
}