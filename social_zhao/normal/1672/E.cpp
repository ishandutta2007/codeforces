#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

int n;

int ask(int x) { cout << "? " << x << endl, cout.flush(); cin >> x; return x; }
void answer(int x) { cout << "! " << x << endl, cout.flush(); }

int main() {
	cin >> n;
	int l = 1, r = n * 2001, ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(ask(mid) == 1) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	for(int i = 2; i <= n; i++) {
		if(!((ans - 1) / i)) continue;
		int now = ask((ans - 1) / i);
		if(!now) continue;
		ans = min(ans, ((ans - 1) / i) * now);
	}
	answer(ans);
	return 0;
}