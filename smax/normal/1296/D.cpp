
// Problem : D. Fight with Monsters
// Contest : Codeforces Round #617 (Div. 3)
// URL : https://codeforces.com/contest/1296/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;

int h[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    for (int i=0; i<n; i++) {
    	cin >> h[i];
    	h[i] %= a + b;
    	if (h[i] == 0)
    		h[i] = a + b;
	}
    
    sort(h, h + n);
    
    int ret = 0;
    for (int i=0; i<n; i++) {
    	if ((h[i] + a - 1) / a - 1 > k)
    		break;
    	k -= (h[i] + a - 1) / a - 1;
    	ret++;
    }
    
    cout << ret << "\n";

    return 0;
}