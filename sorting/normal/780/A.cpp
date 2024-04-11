#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

bool b[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int ans = 0, curr = 0;

	cin >> n;

	for(int i = 0; i < 2 * n; i++){
		int x;

		cin >> x;

		if(b[x]){
			curr--;
			b[x] = false;
		}
		else{
			curr++;
			ans = max(ans, curr);
			b[x] = true;
		}
	}

	cout << ans << "\n";

	return 0;
}