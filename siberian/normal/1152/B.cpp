#include <bits/stdc++.h>

using namespace std;
#define int long long
int x;
void read() {
	cin >> x;
}

int pows(int a, int b) {
	int ans = 1;

	for (int i = 0; i < b; i++)
		ans *= a;
	return ans;
}

vector <int> ans;
void run() {
    if (x % 2 == 0) {
        x++;
        ans.push_back(0);
    }
	while (true) {
		bool kek = false;
		int b = x;
		while (b) {
			if (b % 2 == 0)
				kek = true;
			b /= 2;
		}
		if (!kek)
			break;
		int a = x;
		int cnt = 0;
		bool flag = false;
		while (true) {
			if (a % 2 == 0) {
				flag = true;
			}
			else{
				if (flag)
					break;
			}
			cnt++;
			a /= 2;
			if (a == 0)
				break;
		}
		ans.push_back(cnt);
		x ^= (pows(2, cnt) - 1);
		x++;
	}
}

void write() {
	cout << ans.size() * 2 << endl;
	for (auto i : ans)
		cout << i << " ";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}