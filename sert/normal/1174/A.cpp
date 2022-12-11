#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
    vector<int> a(n * 2);
	for (int i = 0; i < n * 2; i++) {
        cin >> a[i];
    };
    sort(a.begin(), a.end());
    if (a[0] == a.back()) { 
        cout << "-1";
    } else {
        for (int i = 0; i < n * 2; i++) {
            cout << a[i] << " ";
        }
    }
}