#include <bits/stdc++.h>

using namespace std;

const int maxn = 1007;

int n, a[maxn];

bool check(){
	for(int i = 1; i <= n; i++){
		if(a[i] != i){
			return false;
		}
	}

	return true;
}

bool solve(int left){
	if(check()){
		cout << 3 - left << "\n";

		return true;
	}

	if(left == 0){
		return false;
	}

	vector<int> suspects;

	suspects.push_back(1);

	for(int i = 2; i < n; i++){
		if((a[i-1] != a[i]-1 || a[i+1] != a[i]+1) && (a[i-1] != a[i]+1 || a[i+1] != a[i]-1)){
			suspects.push_back(i);
		}
	}

	suspects.push_back(n);

	for(int r: suspects){
		for(int l: suspects){
			if(r <= l){
				break;
			}
			reverse(a + l, a + r + 1);

			if(solve(left - 1)){
				cout << l << " " << r << "\n";

				return true;
			}

			reverse(a + l, a + r + 1);
		}
	}

	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> a[i];		
	}

	solve(3);

	return 0;
}