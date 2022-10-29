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
typedef vector<vector<ll>> vvi;
typedef vector<ll> vi;


int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	string s; cin >> s;
	bool caps = 1;
	rep(i,1,s.length()) {
		if (s[i] <= 'z' && s[i] >= 'a') {
			caps = 0;
		}
	}
	if (caps) {
		if (s[0] <= 'z' && s[0] >= 'a') {
			s[0] = s[0] - 'a' + 'A';
		}
		else {
			s[0] = s[0] - 'A' + 'a';
		}
		rep(i, 1, s.length()) {
			s[i] = s[i] - 'A' + 'a';
		}
	}
	cout << s;
}