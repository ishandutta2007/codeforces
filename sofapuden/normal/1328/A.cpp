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

int main() {

	int t;
	cin >> t;

	rep(i, 0, t) {
		int a, b;
		cin >> a >> b;

		if (a % b == 0) {
			cout << 0 << "\n";

		}
		else {
			cout << b - a % b << "\n";
		}
	
	
	}


	return 0;
}