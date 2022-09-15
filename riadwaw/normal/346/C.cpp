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
	cout.precision(10);
	int t = 1;
	//cin >> t; 
	while (t--)
		solve();

#ifdef DEBUG 
	cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif 
	return 0;
	
}
int x[101010];
int dp[1010101];
int v[1010101];
const int INF = 1000007;
int stop[1010101];
void solve() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) 
		cin >> x[i];
	
	
	sort(x, x + n);
	n = unique(x, x + n) - x;
	int a, b;
	cin >> b >> a;
	int l = b - a + 1;
	for(int i = 0; i <= l; ++i) {
		dp[i] = INF;
		v[i] = 2 ;
	}
	dp[0] = 0;
	for(int i = 0; i < n; ++i) {
		int start = x[i] * ((a  + x[i] - 1)/ x[i]) - a;
		for(int j = start; j < l; j += x[i]) {
			v[j] = x[i];
		}
	}
	
	int cur = 0;
	stop[0] = 1;
	
	for(int i = 0; i < l; ++i) {
		while(i >= stop[cur])
			++cur;
		//cerr<< i << ' ' << cur << endl;
		dp[i] = cur;
		stop[dp[i] + 1] = max(stop[dp[i] + 1], i + v[i]);
	}
	
	cout << dp[l - 1] << endl;
}