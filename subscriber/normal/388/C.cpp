#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<set>
#include<map>
#include<queue>
#include<cstring>
#include<sstream>
#define SS stringstream
#define pw(x) (1ll << (x))
#define m0(x) memset(x, 0, sizeof(x))
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

int n,k, a[11111];

int main() {
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	cin >> n;
	long long A = 0, B = 0;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) cin >> a[j];
		for (int j = 0; j < k / 2; j++) A += a[j];
		for (int j = 0; j < k / 2; j++) B += a[k - 1 - j];
		if (k % 2) v.pb(a[k / 2]);
	}
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < v.size(); i++) {
		if (i % 2 == 0) A += v[i]; else B += v[i];
	}
	cout << A << " " << B << endl;

	return 0;
}