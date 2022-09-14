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
    int n, x = 0, m, l, r;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	for (int j = 0; j < i; j++)
    		if (a[j] > a[i])
    			x ^= 1;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
    	cin >> l >> r;
    	x ^= (r - l + 1) * (r - l) / 2 % 2;
    	if (x)
    		cout << "odd\n";
    	else
    		cout << "even\n";
    }

}