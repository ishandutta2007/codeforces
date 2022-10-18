#include <bits/stdc++.h>

//http://codeforces.com/contest/791/problem/A



using namespace std;


typedef long long LL;
typedef pair<LL,LL> pp;

string newName(vector<string> v) {
	string s = "";
	do {
		s += char('A'+rand()%26);
		s += char('a'+rand()%26);
		s += char('a'+rand()%26);
	}
	while (find(v.begin(), v.end(), s) != v.end());
	return s;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<string> resp(n);
	for (int i = 0; i < n-k+1; i++) {
		cin >> resp[i];
	}
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = newName(v);
	}
	for (int i = 0; i < n-k+1; i++) {
		if (resp[i] == "NO") {
			v[i+k-1] = v[i];
		}
	}
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}