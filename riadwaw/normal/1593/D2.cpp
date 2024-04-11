/// author: Oleg Smirnov
 
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
#include <numeric>
#include <set>
 
using namespace std;
 
int task() {
	int n;
	cin >> n;
 
	vector<int> a(n);
	for (auto& ai : a) {
		cin >> ai;
	}
 
	sort(a.begin(), a.end());
 
	int a0 = a[0];
 
	for (auto& ai : a) {
		ai -= a0;
	}
 
	int ans = 1;
 
	int max_d = a[n-1] + 1;
 
	vector<int> reminder_count(max_d, 0);
        vector<int> reminder(n);
 
	// vector<int> not_worked;
 
	for (int d = 2; d <= max_d; d++) {
		/* if (find_if(not_worked.begin(), not_worked.end(), [d](int nw) {return d % nw == 0; }) != not_worked.end()) {
			continue;
		}*/
 
		int max_count = 0;
 
		/*
		for (int i = 0; i < d; i++) {
			reminder_count[i] = 0;
		}
		*/
 
		for (int i = 0; i < n; ++i) {
                        reminder[i] = a[i] % d;
			max_count = max(max_count, ++reminder_count[reminder[i]]);
		}
 
		if (max_count >= n / 2) {
			ans = d;
		}
 
		for (int i = 0; i < n; ++i) {
			reminder_count[reminder[i]] = 0;
		}
		/*
		else {
			if (d <= 100) {
				not_worked.push_back(d);
			}
		}
		*/
	}
 
	if (ans == max_d) {
		return -1;
	}
 
	return ans;
}
 
int main()
{
	cin.tie(nullptr);
 
	int q;
	cin >> q;
 
	for (int i = 0; i < q; i++) {
		cout << task() << "\n";
	}
 
	return 0;
}