#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	map<string, string> nam;
	string name, ip;
	for (int i = 0; i < n; i++) {
		cin >> name >> ip;
		nam[ip] = name;
	}
	string command;
	for (int i = 0; i < m; i++) {
		cin >> command >> ip;
		string ip2 = ip.substr(0, ip.length()-1);
		cout << command << " " << ip << " #" << nam[ip2] << endl;
	}
	cin >> n;
}