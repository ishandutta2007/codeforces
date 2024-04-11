#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <math.h>
#include <map>

using namespace std;

vector<int> exam_days;
vector<int> exam_level;
int m;

bool can_win(int day) {
	vector<int> last_exam;
	vector<int> needed_days(day + 1);
	for (int i = 0; i < m; i++) {
		last_exam.push_back(-1);
	}
	for (int i = 0; i <= day; i++) {
		if (exam_days[i] != 0) {
			if (last_exam[exam_days[i] - 1] >= 0) {
				needed_days[last_exam[exam_days[i] - 1]] -= 1 + exam_level[exam_days[i] - 1];
			}
			last_exam[exam_days[i] - 1] = i;
			needed_days[i] += 1 + exam_level[exam_days[i] - 1];
		}
	}
	if (needed_days[0] > 1) {
		return false;
	}
	for (int i = 1; i <= day; i++) {
		needed_days[i] += needed_days[i - 1];
		if (needed_days[i] > i + 1) {
			return false;
		}
	}
	for (int i = 0; i < m; i++) {
		if (last_exam[i] == -1) {
			return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	int day;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> day;
		exam_days.push_back(day);
	}
	for (int i = 0; i < m; i++) {
		cin >> day;
		exam_level.push_back(day);
	}

	if (!can_win(n - 1)) {
		cout << -1;
		return 0;
	}
	
	int l = 0, r = n;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (can_win(mid)) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	cout << r + 1;
	return 0;
}