#include <bits/stdc++.h>
using namespace std;

string name;
int n, h;

int main() {
	cin >> name >> n >> h;
	if (name == "Bob") cout << n << endl;
	else {
		double ans = n;
		for (int x = 1; x <= h; x++)
			for (int l = 1; l <= n - 1; l++)
				ans += (n - l) * pow(2., -x) * pow((1. - pow(2., -x)), l - 1) *
					(0.5 - 0.5 * (l - 1) / (pow(2., x) - 1));
		printf("%.10f\n", ans);
	}
}