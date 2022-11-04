#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int MX = 100005;
const int INF = 1e9 + 1;
#define endl '\n'

int Tc;
int n, m;
int a[MX], dif[MX];

bool check(int md) {
	int tot = 0, day = 0;
	for(int i = 0; i < m; i++) {
		if(dif[i] <= 2 * md) continue;
		tot += 2;
	}
	if(tot <= md) return 1;
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

	int i, j;
	for (cin >> Tc; Tc--; ) {
		cin >> n >> m;
		for(int i = 0; i < m; i++) cin >> a[i];
		sort(a, a + m);
		for(int i = 1; i < m; i++) dif[i - 1] = a[i] - a[i - 1] - 1;
		
		dif[m - 1] = a[0] + n - a[m - 1] - 1;
		sort(dif, dif + m);
		
		int st = 0, en = INF, md;
		while(st + 1 < en) {
			md = (st + en) / 2;
			if(check(md)) en = md;
			else st = md;
		}
		int day, cnt = 0;
		if(check(st)) day = st;
		else day = en;
//		cout << day << endl;
		int rlt = 0;
//		cout << day << endl;
		for(int i = m - 1; i >= 0; i--) {
			
			if(dif[i] <= 2 * cnt) {
				continue;
			}
			else if(dif[i] == 2 * cnt + 1) {
				rlt += 1;
				cnt++;
			}
			else {
				rlt += (dif[i] - 2 * cnt - 1);
				cnt += 2;
			}
			
			
//			if(cnt == day - 1) {
//				if(dif[i] <= 2 * cnt) continue;
//				else rlt += (dif[i] - 2 * cnt);
//				cnt += 2;
//				continue;
//			}
//			if(dif[i] <= 2 * cnt + 1) {
//				continue;
//			}
////			cout << i << endl;
//			if(cnt == day - 1) rlt += (dif[i] - 2 * cnt);
//			else rlt += (dif[i] - 2 * cnt - 1);
//			cnt += 2;
		}
//		cout << endl;
//		cout << day << endl;
		cout << n - rlt << endl;
	}
	return 0;
}