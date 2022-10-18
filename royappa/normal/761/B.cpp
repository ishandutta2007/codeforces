#include <bits/stdc++.h>

//http://codeforces.com/contest/761/problem/B

using namespace std;


typedef long long LL;
typedef pair<LL,LL> pp;


int main()
{
	int n, L;
	cin >> n >> L;
	vector<int> A(n), B(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];

	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}
	vector<int> Adiff, Bdiff;
	for (int i = 1; i < n; i++) {
		Adiff.push_back(A[i]-A[i-1]);
		Bdiff.push_back(B[i]-B[i-1]);
	}
	Adiff.push_back(A[0]+(L-A[n-1]));
	Bdiff.push_back(B[0]+(L-B[n-1]));
	for (int i = 0; i < n; i++) {
		rotate(Adiff.begin(), Adiff.begin()+1, Adiff.end());
		if (Adiff == Bdiff) {
			cout << "YES" << endl;
			exit(0);
		}
	}
	cout << "NO" << endl;
	exit(0);
}