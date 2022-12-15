#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;
const int inf = 2e9;

int a[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	sort(a, a + n);

	int mn = inf, cnt = 0;

	for(int i = 0; i < n - 1; i++){
		int d = a[i + 1] - a[i];

		if(d < mn){
			mn = d;
			cnt = 1;
		}
		else{
			if(d == mn){
				cnt++;
			}
		}
	}

	cout << mn << " " << cnt << "\n";

	return 0;
}