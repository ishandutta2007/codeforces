#include <bits/stdc++.h>

using namespace std;

vector<int> v(50001, -2), nt(50001);

void ask(int q) {
	if (v[q] != -2)
		return;
	cout << "? " << q << "\n";
	fflush(stdout);	
	cin >> v[q] >> nt[q];
}

void fin(int h) {
	cout << "! " << h << '\n';
	fflush(stdout);
}

int main() {
	srand(time(NULL));
	int n, x, q, f = -1, ind, cnt = 0;
	cin >> n >> ind >> x;
	ask(ind);
	if (v[ind] >= x) {
		fin(v[ind]);
		exit(0);
	}
	for (int i = 0; i < 1000; i++) {
		q = (long long) rand() * rand() % n + 1;
		ask(q);
		if (v[q] < x && v[q] > f) {
			f = v[q];
			ind = q;
		}
	}
	do {
		ind = nt[ind];
		ask(ind);
		cnt++;
	} while (ind != -1 && v[ind] < x && cnt < 999);
	if (ind == -1)
		fin(-1);
	else
		fin(v[ind]);
}