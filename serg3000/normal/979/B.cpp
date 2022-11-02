#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	vector<long long>a(26);
	vector<long long>b(26);
	long long n;
	string s1, s2, s3;
	cin >> n;
	cin >> s1 >> s2 >> s3;
	long long ma = 0;
	for (long long i = 0; i < (long long)s1.size(); i++) {
		if (s1[i] - 'a' >= 0 && s1[i] - 'a' <= 26) {
			a[s1[i] - 'a'] += 1;
		}
		else {
			b[s1[i] - 'A'] += 1;
		}
	}
	ma = 0;
	for (long long j = 0; j < 26; j++) {
		ma = max(ma, a[j]);
		ma = max(ma, b[j]);
	}
	for (int i = 0; i < 26; i++) {
		a[i] = 0;
		b[i] = 0;
	}
	int cnt1 = ma;
	for (int i = 0; i < (int)s1.size(); i++) {
		if (s2[i] - 'a' >= 0 && s2[i] - 'a' <= 26) {
			a[s2[i] - 'a'] += 1;
		}
		else {
			b[s2[i] - 'A'] += 1;
		}
	}
	ma = 0;
	for (int j = 0; j < 26; j++) {
		ma = max(ma, a[j]);
		ma = max(ma, b[j]);
	}
	int cnt2 = ma;
	for (long long i = 0; i < 26; i++) {
		a[i] = 0;
		b[i] = 0;
	}
	for (long long i = 0; i < (long long)s1.size(); i++) {
		if (s3[i] - 'a' >= 0 && s3[i] - 'a' <= 26) {
			a[s3[i] - 'a'] += 1;
		}
		else {
			b[s3[i] - 'A'] += 1;
		}
	}
	ma = 0;
	for (long long j = 0; j < 26; j++) {
		ma = max(ma, a[j]);
		ma = max(ma, b[j]);
	}
	int cnt3 = ma;

	if (n != 1) {
		cnt1 += n;
		cnt2 += n;
		cnt3 += n;
		cnt1 = min(cnt1, (int)s1.size());
		cnt2 = min(cnt2, (int)s1.size());
		cnt3 = min(cnt3, (int)s1.size());
		if (cnt1 > cnt2 && cnt1 > cnt3) {
			cout << "Kuro";
		}
		else {
			if (cnt2 > cnt1 && cnt2 > cnt3) {
				cout << "Shiro";
			}
			else {
				if (cnt3 > cnt1 && cnt3 > cnt2) {
					cout << "Katie";
				}
				else {
					cout << "Draw";
				}
			}
		}
	}
	else {
		if (cnt1 == (int)s1.size()) {
			cnt1 = cnt1 - 1;
		}
		else {
			cnt1 += n;
		}
		if (cnt2 == (int)s1.size()) {
			cnt2 = cnt2 - 1;
		}
		else {
			cnt2 += n;
		}
		if (cnt3 == (int)s1.size()) {
			cnt3 = cnt3 - 1;
		}
		else {
			cnt3 += n;
		}
		cnt1 = min(cnt1, (int)s1.size());
		cnt2 = min(cnt2, (int)s1.size());
		cnt3 = min(cnt3, (int)s1.size());
		if (cnt1 > cnt2 && cnt1 > cnt3) {
			cout << "Kuro";
		}
		else {
			if (cnt2 > cnt1 && cnt2 > cnt3) {
				cout << "Shiro";
			}
			else {
				if (cnt3 > cnt1 && cnt3 > cnt2) {
					cout << "Katie";
				}
				else {
					cout << "Draw";
				}
			}
		}
	}
	return 0;
}