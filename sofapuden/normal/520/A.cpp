#include<bits/stdc++.h>
#include<unordered_set>
#define rep(i,a,b) for(ll i = a; i<b; i++)
#define dep(i,a,b) for(ll i = a; i>b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (ll fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n";
#define LOG_ints(vec, sep) for (ll fl = 0; fl < MAXSIZE; fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define LSB(i) ((i) & -(i))
#define MAXSIZE 100000000

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;

int main() {
	/*freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);*/
	int n; cin >> n;
	string s; cin >> s; 
	set<int> se;
	for (char h : s) {
		se.insert(h);
	}
	rep(i, 0, 26) {
		if (!se.count('a' + i) && !se.count('A' + i)) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}