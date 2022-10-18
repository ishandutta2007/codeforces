#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int m;
	cin >> m;
	vector<int> A(m), B(m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &A[i]);
	}
	vector<pair<int,int>> v(m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &B[i]);
		v[i] = make_pair(B[i], i);
	}
	sort(v.begin(), v.end());
	sort(A.rbegin(), A.rend());
	vector<int> A2(m);
	for (int i = 0; i < m; i++) {
		int p = v[i].second;
		A2[p] = A[i];
	}
	for (int i = 0; i < m; i++) {
		printf("%d", A2[i]);
		if (i != m-1) printf(" ");
	}
	cout << endl;
	exit(0);
}