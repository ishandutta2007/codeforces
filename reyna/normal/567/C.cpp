//In the name of God
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 9;
int l[N],r[N];
int arr[N];
map<int,int> mp;
main() {
	ios_base::sync_with_stdio(0);
	int n,k; cin >> n >> k;
	for(int i = 0; i < n; ++i) cin >> arr[i];
	for(int i = 0; i < n; ++i) {
		if(arr[i] % k == 0) l[i] = mp[arr[i] / k];
		mp[arr[i]]++;
	}
	mp.clear();
	for(int i = n - 1; ~i; --i) {
		r[i] = mp[arr[i] * k];
		mp[arr[i]]++;
	}
	int res = 0;
	for(int i = 0; i < n; ++i) res += l[i] * r[i];
	cout << res << endl;
	return 0;
}