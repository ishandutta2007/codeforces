#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>

using namespace std;    

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, mn = 1e9 + 2, ans = 1e9 + 2, l = -1e9 - 1;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	mn = min(mn, a[i]);
    }
    for (int i = 0; i < n; i++) {
    	if (a[i] == mn) {
    		ans = min(ans, i - l);
    		l = i;
    	}
    }
    cout << ans;
}