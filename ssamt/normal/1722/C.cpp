#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, k, l;
	int t, n, m, q;
	cin >> t;
	for(int cl=0; cl<t; cl++) {
		cin >> n;
		vector<vector<int>> a;
		for(i=0; i<3; i++) {
			for(j=0; j<n; j++) {
				string s;
				cin >> s;
				int num = s[0]-'a';
				num *= 26;
				num += s[1]-'a';
				num *= 26;
				num += s[2]-'a';
				a.push_back({num, i});
			}
		}
		sort(a.begin(), a.end());
		vector<int> score(3, 0);
		for(i=0; i<a.size(); i++) {
			if(i+1<a.size() && a[i][0] == a[i+1][0]) {
				if(i+2<a.size() && a[i][0] == a[i+2][0]) {
					i += 2;
				} else {
					score[a[i][1]]++;
					score[a[i+1][1]]++;
					i++;
				}
			} else {
				score[a[i][1]] += 3;
			}
		}
		for(i=0; i<3; i++) {
			cout << score[i] << " ";
		}
		cout << endl;
	}
}