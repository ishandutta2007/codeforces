#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 5e5 + 5;
int n, d; 
pair<int, int> p[N];

int main() {
	n = get(), d = get();
	for(int i = 1; i <= n; i++) p[i].second = get(), p[i].first = get();
	int ans = 0;
	sort(p + 1, p + 1 + n, [](pair<int, int> a, pair<int, int> b) { 
		int mxa = max(a.first, a.second), mxb = max(b.first, b.second);
		if(mxa == mxb) return a.second != mxa && b.second == mxb;
		else return mxa < mxb;
	});
	for(int i = 1; i <= n; i++) {
		ans += p[i].second >= d;
		if(p[i].second >= d) d = max(d, p[i].first);
	}
	cout << ans << endl;
	return 0;
}