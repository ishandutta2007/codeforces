#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		if(k < n - 1){
			for(int i = 0; i < n / 2; i++){
				if(i == k) cout << i << " " << n - 1 << endl;
				else if(n - i - 1 == k) cout << n - 1 << " " << n - i - 1 << endl;
				else if(i == 0) cout << 0 << " " << n - 1 - k << endl;
				else cout << i << " " << n - i - 1 << endl;
			}
		}
		else if(n > 4){
			cout << 0 << " " << 2 << endl;
			cout << n - 1 << " " << n - 2 << endl;
			cout << 1 << " " << n - 3 << endl;
			for(int i = 3; i < n / 2; i++) cout << i << " " << n - i - 1 << endl;
		}
		else{
			cout << -1 << endl;
		}
	}
}