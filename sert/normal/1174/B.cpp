#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
    vector<int> a(n);
    vector<bool> u(2, false);
	for (int i = 0; i < n; i++) {
        cin >> a[i];
        u[a[i] % 2] = true;
    };
    if (u[0] && u[1]) 
        sort(a.begin(), a.end());
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}