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
	freopen("output", "w", stdout); 
	clock_t start = clock();
#else 
	//freopen(NAME".in", "r", stdin); 
	//freopen(NAME".out", "w", stdout); 
#endif 
	//ios_base::sync_with_stdio(false);
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

li a[50];
li b[50];

vector<vector<li>> mult(const vector<vector<li>>& a, const vector<vector<li>>& b) {
	 vector<vector<li>> c(40, vector<li>(40, 1e10));
	 int n = 40;
	 for(int i = 0; i < n; ++i) {
		 for(int j = 0; j < n; ++j) {
			 for(int k = 0; k < n; ++k) {
				 c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
			 }
		 }
	 }
	 return c;
}

vector<vector<li>> bpow(const vector<vector<li>>& a, li n){
	if(n == 1)
		return a;
	if(n % 2) {
		return mult(a, bpow(a, n - 1));
	}
	return bpow(mult(a, a), n / 2);
}
int n,m;
int calc(int old, int newV){
	li dp[21][60];
	for(int i = 0; i <=n; ++i) {
		for(int k = 0; k < 60; ++k){
			dp[i][k] = 1e10;
		}
	}
	
	dp[0][old] = 0;
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 59; ++j){
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + a[i]);
		}
		for(int j = 1; j < 60; ++j)
			dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j] + b[i]);
	}
	return dp[n][newV];
}

void solve() {
	
	cin >> n >> m;
	
	
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i){
		cin >> b[i];
	}
	
	
	vector<vector<li>> matrix(40, vector<li>(40, 1e10));
	
	
	for(int newValue = 0; newValue < 40; ++newValue) {
		for(int old = 0; old < 40; ++old) {
			if(newValue - old <= 20 && newValue - old >= -20) {
				matrix[newValue][old] = calc(old, newValue);
			}
		}
	}
	auto p = bpow(matrix, m);
	
	cout <<p[0][0];
	
}