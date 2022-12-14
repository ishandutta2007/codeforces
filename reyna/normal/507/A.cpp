//In the name of God
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn = 1e5 + 1e3;
pair<int,int> arr[Maxn];
int main(){
	int n,k;
	cin >> n >> k;
	for(int i = 0; i < n;i++)
		cin >> arr[i].first,arr[i].second = i;
	sort(arr,arr+n);
	int ans = 0;
	for(int i = 0; i < n;i++){
		k -= arr[i].first;
		if(k < 0)
			break;
		ans++;
	}
	cout << ans << endl;
	for(int i = 0; i < ans;i++){
		cout << arr[i].second+1 << ' ';
	}
	cout << endl;
	return 0;
}