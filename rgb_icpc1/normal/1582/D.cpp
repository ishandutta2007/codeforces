#include <bits/stdc++.h>
#define mx 500005
using namespace std;
int Tc, N, a[mx], b[mx];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	for (cin >> Tc; Tc --;) {
		cin >> N;
		for (int i = 0; i < N; i ++) cin >> a[i];
		int bf = N % 2 + 2;
		for (int i = 0; i < N - bf; i += 2) {
			b[i] = a[i + 1];
			b[i + 1] = -a[i];
		}
		int st = N - bf;
		int s = a[st], t = a[N - 1];
		if (N % 2) s += a[st + 1];
		if (s == 0) {
			s = a[st + 1] + a[N - 1];
			t = a[st];
			if (s == 0) {
				s = a[st] + a[N - 1];
				t = a[st + 1]; 
				b[st + 1] = -s;
				b[st] = b[N - 1] = t;
			}
			else{
				b[st] = -s;
				b[st + 1] = b[N - 1] = t;
			}
		}
		else {
			b[st + 1] = b[st] = t;
			b[N - 1] = -s;
		}
		for (int i = 0; i < N; i ++) cout << b[i] << ' ';
		cout << endl;
	}

}