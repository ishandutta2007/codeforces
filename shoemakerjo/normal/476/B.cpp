#include <bits/stdc++.h>

using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int goal = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == '+') goal++;
		else goal--;
	}
	int cur = 0;
	int qs = 0;
	for (int i = 0; i < s2.length(); i++) {
		if (s2[i] == '+') cur++;
		else if (s2[i] == '-') cur--;
		else qs++;
	}
	double ans = 0.0;
	double fact = 1.0;
	for (int i = 0; i < qs; i++) {
		fact = fact*(0.5);
	}
	for (int i = 0; i <= qs; i++) {
		if (cur + i - (qs-i) != goal) continue;
		double combo = 1.0;
		for (int j = 1; j <= qs; j++) {
			combo = combo*(j+0.0);
		}
		for (int j = 1; j <= i; j++) {
			combo = combo/(j+0.0);
		}
		for (int j = 1; j <=qs-i; j++) {
			combo = combo/(j+0.0);
		}

		ans += combo*fact;
	}
	cout << fixed << setprecision(15);
	cout << ans << endl;
	// cin >> s1;
}