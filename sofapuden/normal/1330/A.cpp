#include<bits/stdc++.h>
#include<unordered_set>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl]<< (fl == vec.size()-1?"\n":sep;)}
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define LSB(i) ((i) & -(i))
#define MAXSIZE 100000

using namespace std;
typedef long long ll;
typedef vector<int> vi;


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		vi v;
		unordered_set<int> ss;
		rep(i, 0, n) {
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		makeUnique(v);
		rep(i, 0, v.size()) {
			ss.insert(v[i]);
		}

		rep(i, 1, x+1) {
			if (ss.count(i)) {
				x++;
			}
		}
		int i = x + 1;
		while (true) {
			if (ss.count(i)) {
				x++;
			}
			else {
				break;
			}
			i++;
		}
		cout << x << endl;
	}
	
}