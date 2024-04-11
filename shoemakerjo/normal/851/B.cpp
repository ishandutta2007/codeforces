#include <bits/stdc++.h>
#define ld long double
#define ll long long
using namespace std;

int main() {
	ll ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	ll as = (bx-cx)*(bx-cx) + (by - cy)*(by-cy);
	// as = sqrt(as);
	ll bs = (ax-cx)*(ax-cx) + (ay - cy)*(ay-cy);
	// bs = sqrt(bs);
	ll cs = (bx-ax)*(bx-ax) + (by - ay)*(by-ay);
	// cs = sqrt(cs);

	// ld aa = acos((bs*bs+cs*cs-as*as)/(2.0*bs*cs));
	// ld ca = acos((as*as+bs*bs-cs*cs)/(2.0*as*bs));
	// if (abs(aa-ca) < 0.1) cout << "Yes\n";
	// else cout << "No\n";
	if ((by-ay)*(cx-bx) == (cy-by)*(bx-ax)) cout << "No\n";
	else if (as == cs) cout << "Yes\n";
	else cout << "No\n";
	cin >> ax;
}