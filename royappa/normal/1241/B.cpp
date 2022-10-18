#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

void run(string s, string t) {
    for (auto c : s) {
        if (t.find(c) != -1) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main()
{
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		string s, t;
		cin >> s >> t;
		run(s, t);
	}
	exit(0);
}