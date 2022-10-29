#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define ll long long
#define LSB(i) ((i) & -(i))
#define MAXSIZE 100000000


using namespace std;

int main() {
	string tmp;
	cin >> tmp;
	int qcount = 0;
	int maxx = 0;
	vector<int> a;
	rep(i, 0, tmp.length()) {
		if (tmp[i] == 'Q') {
			qcount++;
		}
		if (tmp[i] == 'A') {
			a.push_back(qcount);
		}
	}
	rep(i, 0, a.size()) {
		maxx += a[i] * (qcount - a[i]);
	}
	cout << maxx;
}