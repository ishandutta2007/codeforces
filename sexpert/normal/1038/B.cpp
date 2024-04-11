#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	if(n <= 2) cout << "No\n";
	else
	{
	    cout << "Yes\n";
	    if(n % 2)
	    {
	        cout << 1 << " " << n << "\n" << n - 1 << " ";
	        for(int i = 1; i <= n - 1; i++) cout << i << " ";
	        cout << "\n";
	    }
	    else
	    {
	        cout << 2 << " " << 1 << " " << n << "\n" << n - 2 << " ";
	        for(int i = 2; i <= n - 1; i++) cout << i << " ";
	        cout << "\n";
	    }
	}
}