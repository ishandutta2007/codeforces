#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

int cnt, shit;

void EatShit() { for(int i = 1; i <= cnt; i++) cin >> shit; }

int main() {
	while(cnt != 2) {
		cout << "next 2" << endl, cin >> cnt, EatShit(), cout.flush();
		cout << "next 1 2" << endl, cin >> cnt, EatShit(), cout.flush();
	}
	while(cnt != 1) cout << "next 1 2 3 4 5 6 7 8 9 0" << endl, cin >> cnt, EatShit(), cout.flush();
	cout << "done" << endl;
	return 0;
}