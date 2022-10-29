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
	int n;
	cin >> n;
	cout << n / 2 << "\n";

	rep(i, 0, n / 2 - 1) {
		cout << 2 << " ";
	}
	if (n % 2 == 0) {
		cout << 2;
	}
	else {
		cout << 3;
	}
	return 0;
}