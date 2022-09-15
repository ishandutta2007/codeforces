#include <iostream> 
#include <cstdio> 
#include <set> 
#include <map> 
#include <vector> 
#include <queue> 
#include <stack> 
#include <cmath> 
#include <algorithm> 
#include <cstring> 
#include <bitset> 
#include <ctime> 
#include <sstream>
#include <stack> 
#include <cassert> 
#include <list> 
//#include <unordered_set> 
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define mp make_pair 
#define pb push_back 
#define all(s) s.begin(), s.end() 
void solve();

#define NAME "changemeplease"
int main() {
#ifdef DEBUG 
	//cerr << NAME << endl;
	freopen("input", "r", stdin);
	//freopen("output", "w", stdout); 
	clock_t start = clock();
#else 
	//freopen(NAME".in", "r", stdin); 
	//freopen(NAME".out", "w", stdout); 
#endif 
	ios_base::sync_with_stdio(false);
	cout << fixed;
	cout.precision(3);
	int t = 1;
	//cin >> t; 
	while (t--)
		solve();

#ifdef DEBUG 
	cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif 
	return 0;
	
}

vi v;
void solve() {
	int n;
	cin >> n;
	int sumrest = 0;
	for(int i = 0; i < n * 2; ++i) {
		string s;
		cin >> s;
		s = s.substr(s.length() - 3);
		//cout << s << endl;
		stringstream ss(s);
		int a;
		ss >> a;
		if(a != 0){
			v.push_back(a);
			sumrest += 1000 - a;
		}
		
		
	}
	
	
	int sum = 0;
	int ans = 1000000000;
	for(int i = -1; i < int(v.size()); ++i) {
		if(i != -1) {
			sum += v[i];
			sumrest -= 1000 - v[i];
		}
		int nulls = n - (i + 1);
		if(nulls >= 0 && nulls <= int(2 * n - v.size()))
			ans = min(abs(sumrest - sum), ans);
	}
	
	cout << ans / 1000.0;
}