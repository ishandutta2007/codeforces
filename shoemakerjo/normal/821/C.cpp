#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;
int BIT[400000];
void update(int cur, int n, int val) {
	while (cur <= n) {
		BIT[cur]+=val;
		cur += cur&(-cur);
	}
}
int query (int cur, int n) {
	int ans = 0;
	while (cur > 0) {
		ans += BIT[cur];
		cur -= cur&(-cur);
	}
	return ans;
}
int main() {
	for (int i = 0; i <= 400000; i++) BIT[i] = 0;
	int n;
	cin >> n;
	int onStack = 0;
	int added = 0;
	bool sorted = true;
	int curRem = 0;
	string cur;
	int num;
	int ans = 0;
	stack<int> top;
	stack<int> curstack;
	bool ok[n+1];
	// int lastSort
	for (int i = 1; i <= n; i++) ok[i] = false;
	for (int i = 0; i < 2*n; i++) {
		cin >> cur;
		if (cur == "add") {
			cin >> num;
			onStack++;
			added++;
			top.push(num);
			update(num, n, 1);
			curstack.push(num);
		}
		else { //remove type operation
			curRem++;
			int temp = query(curRem, n);
			update(curRem, n, -1);
			if (curstack.size() > 0) {
				int cr = curRem;
				while (curstack.size() > 0) {
					int tempo = curstack.top();
					curstack.pop();
					if (tempo != cr) {
						sorted = false;
					}
					cr++;
				}
			}
			if (sorted) {
				top.pop();
				continue;
			}
			else if (curRem == top.top()) {
				top.pop();
				continue;
			}
			else {
				// cout <<  "number: " << curRem << endl;
				ans++;
				sorted = true;
				top.pop();
			}
		}
	}
	cout << ans << endl;
	cin >> n;
}