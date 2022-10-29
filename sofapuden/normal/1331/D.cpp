#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n";
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define ll long long
#define LSB(i) ((i) & -(i))
#define MAXSIZE 100000000

using namespace std;

int main() {
	string s;
	cin >> s;
	if (s[s.length() - 1] == '0' || s[s.length() - 1] == '2' || s[s.length() - 1] == '4' || s[s.length() - 1] == '6' || s[s.length() - 1] == '8') {
		cout << 0 << "\n";

	}
	else {
		cout << 1 << "\n";
	}
}