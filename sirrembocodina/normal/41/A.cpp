#include <bits/stdc++.h>

using namespace std;
 
string s, t;
        
int main() {
	cin >> s >> t;
	reverse(t.begin(), t.end());
	cout << (s == t ? "YES" : "NO");
}