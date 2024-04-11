#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define in(name, type) type name; cin >> name
#define LOG(x, sep) std::cout << x << sep
#define LOG(x) std::cout << x << "\n"
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

struct Tube {
	ll x, y, pos;
};
bool comparex(Tube& s1, Tube& s2) {
	return (s1.x < s2.x);
}
bool comparey(Tube& s1, Tube& s2) {
	if (s1.y == s2.y) {
		return (s1.x < s2.x);
	}
	else {
		return(s1.y < s2.y);
	}
}

int main() {

	int t;
	cin >> t;
	rep(i, 0, t) {
		vector <ll> money;
		ll a,b,c,n;
		cin >> a >> b >> c >> n;
		money.push_back(a);
		money.push_back(b);
		money.push_back(c);
		sort(all(money));


		if ((a + b + c + n) / 3 >= money[2] && (a + b + c + n) % 3 == 0) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}