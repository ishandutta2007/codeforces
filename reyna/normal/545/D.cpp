//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e6 + 9;
long long cur = 0;
int arr[Maxn];
int main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i = 0; i < n;i++) cin >> arr[i];
	sort(arr,arr+n);
	int ans = 0;
	for(int i = 0; i < n;i++){
		if(cur <= arr[i]) cur += arr[i],ans++;
	}
	cout << ans << endl;
	return 0;
}