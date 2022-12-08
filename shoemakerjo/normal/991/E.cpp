#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll facts[20];
int ct[10];
int curct[10];

ll ans = 0LL;

ll calc() {
	int dig = 0;
	for (int i = 0; i < 10; i++) {
		dig += curct[i];
	}
	ll cur = facts[dig];
	for (int i = 0; i < 10; i++) {
		cur /= facts[curct[i]];
	}
	return cur;
}

void go(int u) {
	if (u == 10) {
		ans += calc();
		if (curct[0] > 0) {
			curct[0]--;
			ans -= calc();
			curct[0]++; //leading 0 case
		}		

		//do some stuff
		return;
	}
	if (ct[u] == 0) {
		curct[u] = 0;
		go(u+1);
		return;
	}
	for (int i = 1; i <= ct[u]; i++) {
		curct[u] = i;
		go(u+1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	facts[0] = 1LL;
	for (int i = 1; i < 20; i++) {
		facts[i] = facts[i-1]*(i+0LL);
	}
	string num;
	cin >> num;
	int dig = 0;
	for  (int i = 0; i < num.length(); i++) {
		ct[num[i]-'0']++;
		dig++;
	}
	go(0);
	cout << ans << endl;
	cin >> ans;
	
}