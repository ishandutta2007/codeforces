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
	int a,b,c,d,co;
	string seq;
	co = 0;
	cin >> a >> b >> c >> d;
	cin >> seq;
	rep(i, 0, seq.length()) {
		if (seq[i] == '1') {
			co += a;
		}
		else if (seq[i] == '2') {
			co += b;
		}
		else if (seq[i] == '3') {
			co += c;
		}
		else if (seq[i] == '4') {
			co += d;
		}
	}
	cout << co;
	return 0;
}