#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;	
    while (t --) {
    	LL n, k;
    	cin >> n >> k;
    	LL sum = k * ((n + k - 1) / k);
    	cout << (sum + n - 1) / n << endl;
    }
}