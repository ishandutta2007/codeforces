#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 20000000 + 10;
int cnt[N];
bool vis[N];
int main() {
	for (int i = 2; i < N; i ++) {
		if (vis[i] == 0) {
			cnt[i] ++;
			for (int j = i + i; j < N; j += i) {
				vis[j] = 1; cnt[j] ++;
			}
		}
	}

	int t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t --) {
    	int c,d,x; 
    	cin >> c >> d >> x;
    	
    	LL ans = 0;
    	for (int i = 1; i * i <= x; i ++) {
    		if (x % i == 0) {
    
    			{
	    			LL y = i;
	    			if ((x/y+d) % c == 0) {
    					LL k = (x/y + d) / c;
    					ans += (1LL<<cnt[k]);
    				}
    			}

      			if (i * i != x)
    			{
	    			LL y = x / i;
	    			if ((x/y+d) % c == 0) {
    					LL k = (x/y + d) / c;
    					ans += (1LL<<cnt[k]);
    				}
    			}  			


    		}
    	}
    	cout << ans << endl;
    }
}