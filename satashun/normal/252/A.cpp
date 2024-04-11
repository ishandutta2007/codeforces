#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, ma;
int a[110];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
	for(int j = i; j < n; j++){
	    int res = 0;
	    for(int k = i; k <= j; k++){
		res ^= a[k];
	    }
	    ma = max(ma, res);
	}
    }
    cout << ma << endl;
    return 0;
}