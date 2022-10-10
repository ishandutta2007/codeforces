#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	while (t--) {
        int n, d;
        cin >> n >> d;

        int ret;
        cin >> ret;
        for (int i=1; i<n; i++) {
            int a;
            cin >> a;
            int change = min(a * i, d) / i;
            ret += change;
            d -= change * i;
        }

        cout << ret << "\n";
	}

	return 0;
}