#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 2020
using namespace std;
int n, a[maxn];
int main(){
	int T; cin >> T;
	while (T--){
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		per(i, n, 1) cout << a[i] << ' ';
		cout << endl;
	}
	return 0;
}