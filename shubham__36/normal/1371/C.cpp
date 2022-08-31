#include <iostream>

using namespace std;

void solve()
{
	long long a,b,n,m;
	cin >> a >> b >> n >> m;
	if(min(a,b)>=m && (a+b)>=(n+m)) cout << "YES" << endl;
	else cout << "NO" << endl;
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