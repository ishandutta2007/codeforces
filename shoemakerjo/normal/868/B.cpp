#include <bits/stdc++.h>

using namespace std;

int main() {
	int h, m, s, t1, t2;
	cin >> h >> m >> s >> t1 >> t2;
	double hd = ((h + m/(60.0) + s/3600.0)*30.0);
	if (hd >= 360.0) hd -= 360.0;
	double md = (m + s/60.0)*6.0;
	if (md >= 360.0) md-=360.0;
	double sd = (s)*6.0;
	double t1d = t1*30.0;
	double t2d = t2*30.0;
	vector<double> hands;
	hands.push_back(hd);
	hands.push_back(md);
	hands.push_back(sd);
	sort(hands.begin(), hands.end());
	bool ok = false;
	for (int i = 0; i < hands.size()-1; i++) {
		if (hands[i] <= t1d  && t1d <= hands[i+1] &&
			hands[i] <= t2d && t2d <= hands[i+1]) {
			ok = true;
		}
	}
	if ((hands[2] <= t1d  || t1d <= hands[0]) &&
		(hands[2] <= t2d || t2d <= hands[0])) {
		ok = true;
	}
	if (ok) cout << "YES\n";
	else cout << "NO\n";
	// cout << hd << " " << md << " " << sd << " " << t1d << " " << t2d << endl;
	// cin >> h;

}