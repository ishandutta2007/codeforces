#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4e5 + 7;

int ans[MAXN];

bool solve(array<int, 4> a, int first){
	int curr = first, idx = 0;
	while(true){
		ans[idx++] = curr; 
		--a[curr];
		//cout << curr << " ";

		int mn = - 1, nxt = -1;
		if(curr != 0 && a[curr - 1]){
			mn = a[curr - 1];
			nxt = curr - 1;
		}
		if(curr != 3 && a[curr + 1]){
			if(a[curr + 1] < mn || mn == -1){
				mn = a[curr + 1];
				nxt = curr + 1;
			}
		}

		if(mn == -1){
			break;
		}

		curr = nxt;
	}
	//cout << endl;

	for(int i = 0; i < 4; ++i){
		if(a[i])
			return false;
	}

	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	array<int, 4> a;
	cin >> a[0] >> a[1] >> a[2] >> a[3];

	int sum = 0;
	for(int i = 0; i < 4; ++i){
		sum += a[i];
	}

	for(int i = 0; i < 4; ++i){
		if(solve(a, i)){
			cout << "YES\n";
			for(int j = 0; j < sum; ++j){
				cout << ans[j] << " ";
			}
			cout << "\n";
			return 0;
		}
	}

	cout << "NO\n";
	return 0;
}