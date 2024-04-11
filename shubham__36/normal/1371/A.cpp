#include <iostream>

using namespace std;

void solve()
{
	int n;
	cin >> n;
	int ans=(n+1)/2;
	cout << ans << endl;
}

int main() 
{
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}