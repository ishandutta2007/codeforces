#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 200020
#define ll long long int 
using namespace std;

int n, a[maxn];

int main(){
	int T; cin >> T;
	while (T--){
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		ll mi = a[1], pre = 0;
		rep(i, 1, n) {
			pre += a[i];
			mi = min(mi, pre);
		}
		cout << -mi << endl;
	}
	return 0;
}