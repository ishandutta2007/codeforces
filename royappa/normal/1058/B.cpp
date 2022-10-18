#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int dot(vector<int> U, vector<int> V) {
	return U[0]*V[0]+U[1]*V[1];
}
int main()
{
	int n, d;
	cin >> n >> d;
	int Ax = 0, Ay = d,
		Bx = d, By = 0,
		Cx = n, Cy = n-d;
	vector<int> AB = {Bx-Ax, By-Ay}, BC = {Cx-Bx, Cy-By};
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int Mx, My;
		cin >> Mx >> My;
		vector<int> AM = {Mx-Ax, My-Ay}, BM = {Mx-Bx, My-By};
		if (0 <= dot(AB, AM) && dot(AB, AM) <= dot(AB, AB) && 0 <= dot(BC, BM) && dot(BC, BM) <= dot(BC, BC)) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
		cout << endl;
	}
	exit(0);
}