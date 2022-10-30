#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	cin >> t;
	for(int cl=0; cl<t; cl++) {
		cin >> n;
		char s[n+1];
		scanf("%s", s);
		vector<char> go;
		for(i=0; i<n; i++) {
			go.push_back(s[i]);
		}
		sort(go.begin(), go.end());
		cout << (go==vector<char>{'T','i','m','r','u'}?"YES":"NO") << endl;
	}
}