#include <bits/stdc++.h>

using namespace std;
#define maxn 100010
int n;
int nums[maxn];

bool check(int val) {
	if (abs(nums[1]-nums[0]) > val) return false;
	set<int> cur;
	cur.insert(nums[0]);
	for (int i = 2; i < n; i++) {
		if (cur.size() == 0) return false;
		cur.insert(nums[i-1]);
		while (cur.size() > 0) {
			set<int>::iterator it = cur.begin();
			if (*it < nums[i]-val) {
				cur.erase(it);
			}
			else break;
		}
		while (cur.size() > 0) {
			set<int>::iterator it = cur.end();
			--it;
			if (*it > nums[i]+val){
				cur.erase(it);
			}
			else break;
		}
	}
	return cur.size() > 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	n += 2;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int high = 1000000000;
	int low = 0;
	while (low < high) {
		int mid = (low+high)/2;
		if (check(mid)) {
			high = mid;
		}
		else {
			low = mid+1;
		}
	}
	cout << low << endl;
	cin >> low;
}