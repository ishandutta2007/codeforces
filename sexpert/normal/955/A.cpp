#include <bits/stdc++.h>
using namespace std;

int main()
{
	int h, m;
	double H, D, C, N;

	cin >> h >> m;
	cin >> H >> D >> C >> N;

	if(h >= 20) cout << 0.8*C*ceil(H/N);
	else cout << min(C*ceil(H/N), 0.8*C*ceil((H + D*(1200.0 - (60.0*h + m)))/N));
}