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
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = min(a, b); i >= 0; i--) {
    	if (a / i + b / i >= n) {
    		cout << i;
    		return 0;
    	}
    }
}