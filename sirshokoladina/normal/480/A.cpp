#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);

int main () {
	#ifdef SG
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	
	int n;
	cin >> n;
	
	vector<pair<int, int> > v(n);
	
	for (int i = 0; i < n; ++i) {
		cin >> v[i].fs >> v[i].sc;
	}
	
	sort(v.begin(), v.end());
	
	int cur = -1;
	
	for (int i = 0; i < n; ++i) {
		if (v[i].sc >= cur) {
			cur = v[i].sc;
		} else {
			cur = v[i].fs;
		}
	}
	
	cout << cur << endl;
	
		
	return 0;
}