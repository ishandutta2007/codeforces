//In the name of God
#include <iostream>
#include <iomanip>
using namespace std;
int n,k;
const int Maxn = 6;
int arr[Maxn];
long double rec(int dep = 0){
	if(dep == k){
		long double ans = 0;
		for(int i = 1; i < n;i++){
			for(int j = 0; j < i;j++){
				if(arr[i] < arr[j])
					ans++;
			}
		}
		return ans;
	}
	long double ans = 0;
	for(int l = 0; l < n;l++){
		for(int r = l; r < n;r++){
			int cnt = 0;
			for(int i = l; i <= r;i++){
				if(cnt >= (r - l + 1)/2)
					break;
				swap(arr[i],arr[l+(r-i)]);
				cnt++;
			}
			ans += rec(dep + 1) * ((long double)1/(((long double)n * (n + 1))/2));
			cnt = 0;
			for(int i = l; i <= r;i++){
				if(cnt >= (r - l + 1)/2)
					break;
				swap(arr[i],arr[l+(r-i)]);
				cnt++;
			}
		}
	}
	return ans;
}
int main(){
	cin >> n >> k;
	for(int i = 0; i < n;i++)
		cin >> arr[i];
	long double ans = rec();
	cout << setprecision(10) << fixed << ans << endl;
	return 0;
}