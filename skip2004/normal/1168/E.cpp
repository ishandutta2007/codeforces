#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 200200;
typedef long long ll;
int a[maxn], b[maxn], c[maxn], ib[maxn];
int k;
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> k;
	int sum = 0;
	for(int i = 0;i < 1 << k;++i) {
		cin >> a[i];
		sum ^= a[i];
		ib[i] = b[i] = c[i] = i;
	}
	if(sum) {
		cout << "Fou" << '\n';
		return 0;
	}
	for(int i = 0;i < 1 << k;++i) {
		int x = i;
		for(;a[x] ^ b[x] ^ c[x];) {
			int y = ib[a[x] ^ c[x]];
			std::swap(b[x], b[y]);
			std::swap(ib[b[x]], ib[b[y]]);
			if(y > i) {
				break;
			}
			std::swap(c[y], c[i + 1]);
			x = y;
		}
	}
	cout << "Shi" << '\n';
	for(int i = 0;i < 1 << k;++i) {
		cout << b[i] << " \n"[i + 1 == 1 << k];
	}
	for(int i = 0;i < 1 << k;++i) {
		cout << c[i] << " \n"[i + 1 == 1 << k];
	}
}