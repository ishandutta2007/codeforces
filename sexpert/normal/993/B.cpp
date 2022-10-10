#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int n, m;
vector<array<int, 2>> A, B;
int trial;

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		A.push_back({x, y});
	}
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		B.push_back({x, y});
	}
	trial = -1;

	for(int i = 0; i < 2; i++) {
		for(auto p : A) {
			int com1 = 0, com2 = 0;
			for(auto q : B) {
				if(p[0] == q[0] && p[1] != q[1])
					com1++;
				if(p[0] == q[1] && p[1] != q[0])
					com1++;
				if(p[1] == q[0] && p[0] != q[1])
					com2++;
				if(p[1] == q[1] && p[0] != q[0])
					com2++;
			}
			if(com1 > 0 && com2 > 0) {
				cout << "-1\n";
				exit(0);
			}
			if(com1 + com2 == 0)
				continue;
			if(com1) {
				if(trial > -1 && trial != p[0])
					trial = -2;
				if(trial != -2)
					trial = p[0];
			}
			if(com2) {
				if(trial > -1 && trial != p[1])
					trial = -2;
				if(trial != -2)
					trial = p[1];
			}
		}
		swap(A, B);
	}
	if(trial == -2)
		cout << "0\n";
	else
		cout << trial << '\n';
}