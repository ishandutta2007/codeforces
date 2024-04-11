#include <bits/stdc++.h>
using namespace std;
const int M = 100001;

int a[M];
char s[M];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	scanf("%s", s + 1);
    a[0] = 0;
    for(int i = 1; i <= n; i ++) {
		a[i] = a[i-1];
		if(s[i] == 'a') a[i] ++;
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        int st, en;
		st = i - 1, en = n + 1;
        while(en > st + 1) {
            int mid = (en + st) / 2;
			if(a[mid] - a[i-1] <= k) st = mid;
			else en = mid;
        }
        ans = max(ans, st - i + 1);
        st = i - 1, en = n + 1;
        while(en > st + 1) {
			int mid = (en + st) / 2;
			if(mid - i + 1 - (a[mid] - a[i-1]) <= k) st = mid;
			else en = mid;
        }
        ans = max(ans, st - i + 1);
    }
    cout << ans << endl;
}