#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n;
int x[N], a[N];
int lst[N];

int main() {
	cin >> n;
	for(int i = 2; i <= n; i++) cout << "XOR 1 " << i << endl, cin >> x[i], cout.flush();
	for(int i = 2; i <= n; i++) {
		if(lst[x[i]]) {
			cout << "AND " << lst[x[i]] << " " << i << endl, cin >> a[i], cout.flush();
			a[1] = a[i] ^ x[i];
			for(int j = 2; j <= n; j++) a[j] = a[1] ^ x[j];
			cout << "! ";
			for(int j = 1; j <= n; j++) cout << a[j] << " ";
			return 0;
		}
		else lst[x[i]] = i;
		if(x[i] == 0) {
			cout << "AND " << 1 << " " << i << endl, cin >> a[1], cout.flush();
			for(int j = 2; j <= n; j++) a[j] = a[1] ^ x[j];
			cout << "! ";
			for(int j = 1; j <= n; j++) cout << a[j] << " ";
			return 0;
		}
	}
	int x1 = lst[1], x2 = lst[n - 2];
	int a1 = 0, a2 = 0;
	cout << "AND " << 1 << " " << x1 << endl, cin >> a1, cout.flush();
	cout << "AND " << 1 << " " << x2 << endl, cin >> a2, cout.flush();
	a[1] = (a1 & (n - 1)) | (a2 & 1);
	for(int j = 2; j <= n; j++) a[j] = a[1] ^ x[j];
	cout << "! ";
	for(int j = 1; j <= n; j++) cout << a[j] << " ";
	return 0;
}