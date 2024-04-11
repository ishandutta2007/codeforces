#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define maxn 200001
int vals[maxn];
int sbig[maxn];
int ebig[maxn];
int sbit[maxn];
int ebit[maxn];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> vals[i];
		sbig[i] = i;
		ebig[i] = i;
		sbit[i] = -1;
		ebit[i] = -1;
	}
	int cur;
	stack<int> nums;
	for (int i = 0; i < n; i++) {
		sbig[i] = i;
		while (!nums.empty()) {
			cur = nums.top();
			if (vals[cur] > vals[i]) {
				sbig[i] = cur+1;
				break;
			}
			else {
				nums.pop();
			}
		}
		if (nums.size() == 0) {
			sbig[i] = 0;
		}
		nums.push(i);
		// cout << "iS: " << sbig[i] << endl;
	}
	while (!nums.empty()) {
		nums.pop();
	}
	for (int i = n-1; i >= 0; i--) {
		ebig[i] = i;
		while (!nums.empty()) {
			cur = nums.top();
			if (vals[cur] >= vals[i]) {
				ebig[i] = cur-1;
				break;
			}
			else {
				nums.pop();
			}
		}
		if (nums.size() == 0) {
			ebig[i] = n-1;
		}
		nums.push(i);
		// cout << "iE: " << ebig[i] << endl;
	}
	for (int i = 0; i <= 30; i++) {
		int prev = -1;
		for (int j = 0; j < n; j++) {
			if (vals[j] & (1 << i)) {
				prev = j;
				continue;
			}
			else{
				if (prev==-1) continue;
				if (prev > sbit[j] || sbit[j] == -1) {
					sbit[j] = prev;
				}
			}
		}
	}
	for (int i = 0; i <= 30; i++) {
		int prev = -1;
		for (int j = n-1; j >= 0; j--) {
			if (vals[j] & (1 << i)) {
				prev = j;
				continue;
			}
			else{
				if (prev==-1) continue;
				if (prev < ebit[j] || ebit[j] == -1) {
					ebit[j] = prev;
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		// cout << "iinfo:  " << i << "  " << sbit[i] << "  " << ebit[i] <<  "  big  " << 
		// 	sbig[i] << " " << ebig[i] << endl;
		if (sbit[i] == -1 && ebit[i] == -1) continue;
		ll cur = 0;
		if (sbit[i] >= sbig[i]) {
			cur += (sbit[i]-sbig[i]+1LL)*(ebig[i]-i+1LL);
		}
		if (ebit[i] <= ebig[i] && ebit[i] != -1) {
			cur += (i-sbig[i]+1LL)*(ebig[i]-ebit[i]+1LL);
		}
		if (sbit[i] >= sbig[i] && (ebit[i] <= ebig[i] && ebit[i] != -1)) {
			cur -= (sbit[i]-sbig[i]+1LL)*(ebig[i]-ebit[i]+1LL);
		}
		// cout << "i: " << i << "  " << cur << endl;
		ans = ans+cur;
	}
	cout << ans << endl;
	// cin >> n;

}