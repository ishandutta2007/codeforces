#include <bits/stdc++.h>

using namespace std;

const int N = 1007;
const int inf = 1e9;

int a[N][N];
int n, m;

bool good[N][N];

bool check(int mid){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			good[i][j] = false; 
		}
	}

	for(int i = 0; i < n; i++){
		vector<int> v;
		for(int j = 0; j < m; j++){
			if(a[i][j] >= mid){
				v.push_back(j);
			}
		}

		for(int x1: v){
			for(int x2: v){
				if(x1 == x2){
					continue;
				}

				if(good[x1][x2]){
					return true;
				}

				good[x1][x2] = true;
			}
		}
	}

	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}

	int l = 0, r = inf;

	while(l != r){
		int mid = (l + r + 1) / 2;

		if(check(mid)){
			l = mid;
		}
		else{
			r = mid - 1;
		}
	}

	cout << l << "\n";

	return 0;
}