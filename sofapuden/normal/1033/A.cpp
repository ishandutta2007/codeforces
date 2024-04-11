#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a-1; i>=b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { cout << vec[fl]<< sep; } cout << "\n";
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { cout << vec[fl]<< sep; } cout << "\n"
#define all(x) (x).begin(), (x).end()
#define LSB(i) ((i) & -(i))
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;


int main() {
	int trash; cin >> trash;
	int t1, t2, t3, t4, t5, t6; cin >> t1 >> t2 >> t3 >> t4 >> t5 >> t6;
	if ((min(t3, t5) > t1 || max(t3, t5) < t1) && (min(t4, t6) > t2 || max(t4, t6) < t2)) {
		cout << "YES\n";
		return 0;
	}
	cout << "NO\n";
	return 0;
}