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
		int trash;
		cin >> trash;

		string finalN;
		cin >> finalN;
		string a,b;

		rep(j, 0, trash) {
			a.append("0");
		}
		finalN[0] = '1';
		a[0] = '1';
		rep(j, 1, trash) {
			if (finalN[j] == '1') {
				finalN[j] = '0';
				a[j] = '1';
				break;
			}
			else if(finalN[j] == '2'){
				finalN[j] = '1';
				a[j] = '1';
			}
		}
		cout << a << "\n" << finalN << "\n";

	}


	return 0;
}