#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <unordered_set>
#include <map>
#include<unordered_map>
#include <bitset>
#include <random>
#include <ctime>
using namespace std;
#define int long long
signed main() {
	vector<vector<int>>a(3, vector<int>(2));
	cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1] >> a[2][0] >> a[2][1];
	sort(a.begin(), a.end());
	vector<vector<int>>a1 = a;
	int cnt = 0;
	if (a1[1][1] >= a1[0][1] && a1[1][1] >= a1[2][1]) {
		while (a1[1][1] != max(a1[0][1], a1[2][1])) {
			cnt++;
			a1[1][1]--;
		}
		for (int i = a1[0][0]; i <= a1[2][0]; i++) {
			cnt++;
		}
		for (int i = a1[0][1]; i < a1[1][1]; i++) {
			cnt++;
		}
		for (int i = a1[2][1]; i < a1[1][1]; i++) {
			cnt++;
		}
	}
	else {
		if (a1[1][1] <= a1[0][1] && a1[1][1] <= a1[2][1]) {
			while (a1[1][1] != min(a1[0][1], a1[2][1])) {
				cnt++;
				a1[1][1]++;
			}
			for (int i = a1[0][0]; i <= a1[2][0]; i++) {
				cnt++;
			}
			for (int i = a1[0][1]; i > a1[1][1]; i--) {
				cnt++;
			}
			for (int i = a1[2][1]; i > a1[1][1]; i--) {
				cnt++;
			}
		}
		else {
			for (int i = a1[0][0]; i <= a1[2][0]; i++) {
				cnt++;
			}
			for (int i = a1[0][1]; i > a1[1][1]; i--) {
				cnt++;
			}
			for (int i = a1[2][1]; i > a1[1][1]; i--) {
				cnt++;
			}
			for (int i = a1[0][1]; i < a1[1][1]; i++) {
				cnt++;
			}
			for (int i = a1[2][1]; i < a1[1][1]; i++) {
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
	if (a[1][1] >= a[0][1] && a[1][1] >= a[2][1]) {
		while (a[1][1] != max(a[0][1], a[2][1])) {
			cout << a[1][0] << " " << a[1][1] << '\n'; 
			a[1][1]--;
		}
		for (int i = a[0][0]; i <= a[2][0]; i++) {
			cout << i << " " << a[1][1] << '\n';
		}
		for (int i = a[0][1]; i < a[1][1]; i++) {
			cout << a[0][0] << " " << i << '\n';
		}
		for (int i = a[2][1]; i < a[1][1]; i++) {
			cout << a[2][0] << " " << i << '\n';
		}
	}
	else {
		if (a[1][1] <= a[0][1] && a[1][1] <= a[2][1]) {
			while (a[1][1] != min(a[0][1], a[2][1])) {
				cout << a[1][0] << " " << a[1][1] << '\n';
				a[1][1]++;
			}
			for(int i = a[0][0]; i <= a[2][0]; i++){
				cout << i << " " << a[1][1] << '\n';
			}
			for (int i = a[0][1]; i > a[1][1]; i--) {
				cout << a[0][0] << " " << i << '\n';
			}
			for (int i = a[2][1]; i > a[1][1]; i--) {
				cout << a[2][0] << " " << i << '\n';
			}
		}
		else {
			for (int i = a[0][0]; i <= a[2][0]; i++) {
				cout << i << " " << a[1][1] << '\n';
			}
			for (int i = a[0][1]; i > a[1][1]; i--) {
				cout << a[0][0] << " " << i << '\n';
			}
			for (int i = a[2][1]; i > a[1][1]; i--) {
				cout << a[2][0] << " " << i << '\n';
			}
			for (int i = a[0][1]; i < a[1][1]; i++) {
				cout << a[0][0] << " " << i << '\n';
			}
			for (int i = a[2][1]; i < a[1][1]; i++) {
				cout << a[2][0] << " " << i << '\n';
			}
		}
	}
	return 0;
}