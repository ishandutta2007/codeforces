#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 400020
using namespace std;

int n;
int a[maxn];

int main(){
		
	ios::sync_with_stdio(false);
	
	int T;
	cin >> T;
	while (T--){
		cin >> n;
		rep(i, 1, n) cin >> a[i]; 
		int l = 0;
		rep(i, 1, n){
			if (a[i] < i - 1) break;
			l = i;
		}
		int r = n + 1;
		per(i, n, 1){
			if (a[i] < n - i) break;
			r = i;
		}
		if (l < r) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	return 0;
}