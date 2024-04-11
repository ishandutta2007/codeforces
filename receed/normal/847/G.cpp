#include <bits/stdc++.h>

using namespace std;

int a[1000];

int main() {
#ifdef FLOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
            a[j] += s[j] - '0';
	}
	int ans = 0;
    for (int i = 0; i < 1000; i++)
        ans = max(ans, a[i]);
    cout << ans;
}