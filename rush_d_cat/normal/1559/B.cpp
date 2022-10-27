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
    	string s;
    	cin >> n >> s;
    	for (int i = 0, j = 0; i < n; i = j) {
    		if (s[i] == '?') {
    			while (j < n && s[i] == s[j]) j ++;
    			//printf("[%d, %d)\n", i, j);
    			// [i, j)
    			int f1 = 0, f2 = 0;
    			for (int k = i; k < j; k ++) {
    				s[k] = ((k - i) % 2 == 0 ? 'R' : 'B');
    			}
    			for (int k = i; k <= j; k ++) {
    				if (k < n && k - 1 >= 0 && s[k] != s[k - 1]) f1 ++; 
    			}
    			for (int k = i; k < j; k ++) {
    				s[k] = ((k - i) % 2 == 0 ? 'B' : 'R');
    			}
    			for (int k = i; k <= j; k ++) {
    				if (k < n && k - 1 >= 0 && s[k] != s[k - 1]) f2 ++; 
    			}
    			if (f1 >= f2) {
    				for (int k = i; k < j; k ++) {
    					s[k] = (k - i) % 2 == 0 ? 'R' : 'B';
    				}
    			} else {
	    			for (int k = i; k < j; k ++) {
	    				s[k] = (k - i) % 2 == 0 ? 'B' : 'R';
	    			}    				
    			}
    		} else {
    			j ++;
    		}
    	}
    	cout << s << endl;
    }

}