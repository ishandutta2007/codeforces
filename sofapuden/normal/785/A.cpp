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
	int n, result;
	cin >> n;
	result = 0;
	rep(i, 0, n) {
		string tmp;
		cin >> tmp;
		if (tmp == "Tetrahedron") {
			result += 4;
		}
		else if (tmp == "Cube")
			result += 6;
		else if (tmp == "Octahedron")
			result += 8;
		else if (tmp == "Dodecahedron")
			result += 12;
		else {
			result += 20;
		}
	}
	cout << result;

	return 0;
}