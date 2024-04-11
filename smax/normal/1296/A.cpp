
// Problem : A. Array with Odd Sum
// Contest : Codeforces Round #617 (Div. 3)
// URL : https://codeforces.com/contest/1296/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int t;
    cin >> t;
    while (t--) {
    	int n;
    	cin >> n;
    	
    	int even = 0, odd = 0;
    	for (int i=0; i<n; i++) {
    		int a;
    		cin >> a;
    		
  			if (a % 2)
  				odd++;
  			else
  				even++;
    	}
    	
    	if (odd % 2 == 1 || odd % 2 == 0 && odd > 0 && even > 0)
    		cout << "YES\n";
    	else
    		cout << "NO\n";
    }

    return 0;
}