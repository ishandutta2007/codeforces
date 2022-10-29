#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a-1; i>=b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { cout << vec[fl]<< sep; } cout << "\n";
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { cout << vec[fl]<< sep; } cout << "\n"
#define all(x) (x).begin(), (x).end()
#define LSB(i) ((i) & -(i))
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
void solve() {
	int a,b,p;
	string s;
	cin >> a >> b >> p >> s; 
	int len = s.length() - 1;
	int pos = len+1;
	int sum = 0;
	char curr = s[len-1];
	dep(i, len-1, -1) {
		if (s[i] != curr) {
			if (curr == 'A') {
				sum += a;
				if (sum > p) {
					cout << pos << endl;
					return;
				}
				pos = i+2;
			}
			else {
				sum += b;
				if (sum > p) {
					cout << pos << endl;
					return;
				}
				pos = i+2;
			}
			curr = s[i];
		}		
	}
	if (curr == 'A') {
		sum += a;
	}
	else {
		sum += b;
	}
	if (sum > p) {
		cout << pos << endl;
		return;
	}
	cout << 1 << endl;

}
int main() {
	int n;
	string s;
	cin >> n >> s;
	vector<pair<int,int>> v(n);
	rep(i, 0, n) {
		v[i].first = s[i];
		v[i].second = i;
	}
	sort(all(v));
	reverse(all(v));
	int counter = 0;
	bool ok = 1;
	while (ok) {
		ok = 0;

		rep(i, 0, v.size()) {
			bool ok2 = 0;
			if (v[i].second != 0) {
				if (s[v[i].second - 1] == v[i].first - 1) {
					ok2 = 1;
					counter++;
					ok = 1;
					v[i].first = 0;
					rep(j, 0, v.size()) {
						if (v[j].second > v[i].second) {
							v[j].second--;
						}
					}
					s.erase(s.begin() + v[i].second);
					break;
				}
			}
			if (v[i].second != s.length() - 1 && ok2 == 0) {
				if (s[v[i].second + 1] == v[i].first - 1) {
					counter++;
					ok = 1;
					v[i].first = 0;

					rep(j, 0, v.size()) {
						if (v[j].second > v[i].second) {
							v[j].second--;
						}
					}
					s.erase(s.begin() + v[i].second);
					break;
				}
			}
		}
	}
	cout << counter << endl;
}