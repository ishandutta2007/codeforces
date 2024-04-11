#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
    	int n;
    	cin >> n;
    	vector<int> a(n);
    	for (int i = 0; i < n; i ++) cin >> a[i];
    	int p = -1;
    	for (int i = n - 1; i >= 0; i --) 
    		if (a[i] == 0) {
    			p = i; break;
    		}
    	//printf("p = %d\n", p);
    	if (p != -1) {
    		for (int i = 0; i <= p; i ++) cout << (i+1) << " ";
    		cout << (n+1) << " ";
    		for (int i = p + 1; i < n; i ++) cout << (i+1) << " ";
    		cout << endl;
    	} else {
    		cout << (n+1) << " ";
    		for (int i = 0; i < n; i ++) {
    			cout << (i+1) << " ";
    		}
    		cout << endl;
    	}

    } 
}