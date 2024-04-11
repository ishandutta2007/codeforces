#include <iostream>
#include <algorithm>

using namespace std;

bool flag;
int n , a[5001] , f[5001] , ans = 0;

int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i++){
		flag = true;
		for(int j = 1 ; j <= ans ; j++)
			if(f[j] <= a[i]){
				f[j]++;
				flag = false;
				break;
			}
		if(flag)
			f[++ans] = 1;
	}
	cout << ans << endl;
	return 0;
}