#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;


int main(){
	int n;
	cin >> n;
	if (n == 1) {
		cout << "? 1 1" << endl;
		string s;
		cin >> s;
		cout << "! " << s << endl;
		return 0;
	}
	map <string, int> cnt;
	cout << "? 1 " << n << endl;
	for (int i = 0; i < n * (n + 1) / 2; i++) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		cnt[s]++;
	}
	cout << "? 1 " << n - 1 << endl;
	for (int i = 0; i < n * (n - 1) / 2; i++) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		cnt[s]--;
	}
	vector <string> a(n + 1);
	for (auto q : cnt) {
		assert(q.second >= 0 && q.second <= 1);
		if (q.second) {
			string s = q.first;
			a[s.size()] = s;
		}
	}
	vector <int> cntw(31, 0);
	string res = "";
	for (int i = 0; i < n; i++) {
		auto cp = cntw;
		//cout << i << " " << a[i + 1] << "\n";
		for (char c : a[i + 1]) {
			cp[c - 'a']--;
		}
		int d = -1;
		for (d = 0; d < 31; d++) {
			if (cp[d] < 0) {
				break;
			}
		}
		//cout << i << " " << d << endl;
		assert(d != 31);
		cntw[d]++;
		res += (char) (d + 'a');
	}
	reverse(res.begin(), res.end());
	cout << "! " << res << endl; 
}