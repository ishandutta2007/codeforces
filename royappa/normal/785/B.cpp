#include <bits/stdc++.h>

//http://codeforces.com/contest/785/problem/D

using namespace std;


typedef long long LL;
typedef pair<int,int> pp;

void getvec(int n, vector<pp> &v) {
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
}

int f(vector<pp> &A, vector<pp> &B) {
	sort(B.begin(), B.end());
	int diff = 0;
	for (int i = 0; i < A.size(); i++) {
		diff = max(diff, B[B.size()-1].first-A[i].second);
	}
	return diff;
}

int main()
{
	int n, m;
	cin >> n;

	vector<pp> A, B;
	getvec(n, A);
	cin >> m;
	getvec(m, B);
	cout << max(f(A, B), f(B, A)) << endl;

	exit(0);
}