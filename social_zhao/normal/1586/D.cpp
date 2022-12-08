#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 105;
int n, a[N], p[N];

int ask() {
	int res;
	cout << "? "; for(int i = 1; i <= n; i++) cout << a[i] << " ";
	cout << endl;
	cin >> res;
	return res;
}

void answer() {
	cout << "! "; for(int i = 1; i <= n; i++) cout << p[i] << " ";
	cout << endl;
}

int main() {
	n = get();
	p[n] = 1;
	int flag = 0;
	for(int i = 2; i <= n; i++) {
		a[n] = 1;
		for(int j = 1; j < n; j++) a[j] = i;
		int res = ask();
		if(!res) { p[n] = i - 1; flag = 1; break; }
	}
	if(!flag) p[n] = n;
	for(int i = 1; i < p[n]; i++) {
		for(int j = 1; j < n; j++) a[j] = p[n] - i + 1;
		a[n] = 1;
		p[ask()] = i;
	}
	for(int i = p[n] + 1; i <= n; i++) {
		for(int j = 1; j < n; j++) a[j] = 1;
		a[n] = i - p[n] + 1;
		p[ask()] = i;
	}
	answer();
	return 0;
}