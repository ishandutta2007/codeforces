#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[102];
		for(int i = 0; i < n; i++) cin >> a[i];
		int ans = 0;
		for(int l = 0; l < n; l++){
			int s = 0;
			for(int r = l; r < n; r++){
				s++;
				if(a[r] == 0) s++;
				ans += s;
			}
		}
		cout << ans << endl;
	}
}