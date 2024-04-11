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

int main(){
	ll N;
	cin >> N;
	if (N == 1 || N == 2) {
		cout << -1 << endl; return 0;
	}
	ll tmp = N * N / 2;
	if (N % 2 == 1) {
		cout << tmp <<" "<< tmp + 1 << endl;
		return 0;
	}
	tmp /= 2;
	cout << tmp - 1 << " " << tmp + 1 << endl;
}