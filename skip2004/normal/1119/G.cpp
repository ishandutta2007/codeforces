#include<bits/stdc++.h>
const int maxn = 1000100;
using std::cin;
using std::cout;
using ll = long long;
int a[maxn];
int hp[maxn];
int n, m;
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	int sum = 0;
	cin >> n >> m;
	for(int i = 1;i <= m;++i) {
		cin >> hp[i];
		sum += hp[i];
		a[i] = sum % n;
	}
	a[m] = n;
	std::sort(a + 1, a + m + 1);
	for(int i = m;i >= 1;--i) {
		a[i] -= a[i - 1];
	}
	cout << (sum + n - 1) / n << '\n';
	for(int i = 1;i <= m;++i) {
		cout << a[i] << " \n"[i == m];
	}
	int idx = 1;
	for(int i = 1;i <= m;++i) {
		while(hp[i] > 0) {
			hp[i] -= a[idx];
			idx += 1;
			cout << i;
			if(idx <= m) {
				cout << ' ';
			} else {
				idx = 1;
				cout << '\n';
			}
		}
	}
	if(idx != 1)
	for(;idx <= m;++idx) {
		cout << m << ' ';
	}
}