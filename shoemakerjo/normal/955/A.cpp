#include <bits/stdc++.h>

using namespace std;

int main() {
	int hh, mm, H, D, C, N;
	cin >> hh >> mm >> H >> D >> C >> N;
	double ans = 0.0;
	int buy = H/N;
	if (H%N != 0) buy++;
	ans = buy*C;


	int inc = 0;
	if (hh < 20) {
		inc += 60-mm;
		inc += 60*(20-hh-1);
	}
	buy = (H+inc*D)/N;
	// cout << "after val  " << H+inc*D << endl;
	if ((H+inc*D) % N != 0) buy++;
	ans = min(ans, buy*0.8*C);
	cout << fixed << setprecision(10);
	cout << ans << endl;
	cin >> hh;
}