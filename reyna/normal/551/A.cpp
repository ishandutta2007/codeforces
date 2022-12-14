//In the name of God
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int Maxn = 1e6 + 9;
int arr[Maxn];
int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i = 0; i < n;i++) {
		cin >> arr[i];
	}
	for(int i = 0; i < n;i++) {
		int cnt = 0;
		for(int j = 0; j < n;j++) if(arr[j] > arr[i]) cnt++;
		cout << cnt + 1 << ' ';
	}
	return 0;
}