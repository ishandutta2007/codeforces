#include <bits/stdc++.h>

#define maxn 100001
#define pii pair<int, int>

using namespace std;

int seg[maxn*4];
int n;

int RMQ(int ss, int se, int qs, int qe, int index) {
	if (qs <= ss && qe >= se) {
		return seg[index];
	}
	if (se < qs || ss > qe) {
		return -1;
	}
	int mid = (ss+se)/2;
	return max(RMQ( ss, mid, qs, qe, 2*index+1),
		RMQ(mid+1, se, qs, qe, 2*index+2));
}

int query(int qs, int qe) {
	return RMQ(1, n, qs, qe, 0);
}

void update(int spot, int val, int ss, int se, int index) {
	if (ss == spot && se == spot) {
		seg[index] = val;
		return;
	}
	if (spot < ss || spot > se || se < ss) {
		return;
	}
	int mid = (ss + se)/2;
	update(spot, val, ss, mid, index*2+1);
	update(spot, val, mid+1, se, index*2+2);
	seg[index] = max(seg[index*2+1], seg[index*2+2]);
}

void useg(int spot, int val) {
	update(spot, val, 1, n, 0);
}

int main() {
	cin >> n;
	int nums[n+1];
	for (int i= 1; i <= n; i++) {
		cin >> nums[i];
	}
	int curmax = -1;
	//we have to find first guy that would beat the current person
	//do Range Maximum query over people between them
	stack<int> mon;
	int time[n+1];
	for (int i = 1; i <= n; i++) {
		time[i] = 0;
	}
	for (int i = 0; i < 4*maxn; i++) {
		seg[i] = -1;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		// cout << "i: " << i <<  endl;
		while (!mon.empty()) {

			int cur = mon.top();
			if (nums[cur] < nums[i]) {
				mon.pop();
			}
			else break;
		}
		if (mon.empty()) {
			time[i] = 0;
		}
		else {
			int bef = mon.top();
			int qu = query(bef+1, i-1);
			qu = max(qu, 0);
			time[i] = qu+1;
			ans = max(ans, qu+1);
		}
		// cout << "time: " << time[i] << endl;
		useg(i, time[i]);
		mon.push(i);
	}
	cout << ans << endl;
	cin >> n;
}