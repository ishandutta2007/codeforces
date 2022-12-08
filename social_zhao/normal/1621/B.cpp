#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int L[N], R[N], C[N], n;

void solve() {
	int mxl = 0, mxr = 0, mlen = 0;
	n = get();
	for(int i = 1; i <= n; i++) L[i] = get(), R[i] = get(), C[i] = get();
	L[0] = 0x3f3f3f3f, R[0] = -0x3f3f3f3f;
	for(int i = 1; i <= n; i++) {
		if(L[i] < L[mxl] || (L[i] == L[mxl] && C[i] < C[mxl])) mxl = i;
		if(R[i] > R[mxr] || (R[i] == R[mxr] && C[i] < C[mxr])) mxr = i;
		if((R[i] - L[i] + 1 > R[mlen] - L[mlen] + 1) || (R[i] - L[i] + 1 == R[mlen] - L[mlen] + 1 && C[i] < C[mlen])) mlen = i;
		int ans = 0x3f3f3f3f3f3f3f3f;
		if(mxl == mxr) ans = min(ans, C[mxl]);
		else ans = min(ans, C[mxl] + C[mxr]);
		if(L[mlen] <= L[mxl] && R[mlen] >= R[mxr]) ans = min(ans, C[mlen]);
		cout << ans << endl;
	}
}

main() {
	int T = get();
	while(T--) solve();
	return 0;
}