#include<bits/stdc++.h>
#include<chrono>
#include<windows.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define in(name, type) type name; cin >> name
#define LOG(x, sep) std::cout << x << sep
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define ll long long
#define LSB(i) ((i) & -(i))
#define MAXSIZE 200005

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> nv;
	vector<string> mv;
	rep(i, 0, n) {
		string tmp;
		cin >> tmp;
		nv.push_back(tmp);
	}
	rep(i, 0, m) {
		string tmp;
		cin >> tmp;
		mv.push_back(tmp);
	}
	int t;
	cin >> t;
	rep(i, 0, t) {
		int y;
		cin >> y;
		cout << nv[(y-1) % n] << mv[(y-1) % m] << "\n";
	}

	return 0;
}