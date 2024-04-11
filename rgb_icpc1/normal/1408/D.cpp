#include<bits/stdc++.h>
using namespace std;

#define MX 2005
#define MM 1000005
int a[MX], b[MX], c[MX], d[MX], val[MM];

int main() {
	int N, M; cin >> N >> M;
	for(int i = 0; i < N; i ++) cin >> a[i] >> b[i];
	for(int i = 0; i < M; i ++) cin >> c[i] >> d[i];
	for(int i = 0; i < N ; i ++) for(int j = 0; j < M; j ++) {
		if(a[i] <= c[j] && b[i] <= d[j]) val[c[j] - a[i]] = max(val[c[j] - a[i]], d[j] - b[i] + 1);
	}
	int ans = INT_MAX;
	for(int i = MM - 1; i >= 0; i --) val[i] = max(val[i], val[i + 1]);
	for(int i = 0; i < MM; i ++) ans = min(val[i] + i, ans);
	cout << ans << endl;
	
	return 0;
}