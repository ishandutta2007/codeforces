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

int main() {
#ifdef DEBUG 
	freopen("input", "r", stdin);
	//freopen("output", "w", stdout); 
	clock_t start = clock();
#else 

	//freopen("taxi.in", "r", stdin); 
	//freopen("taxi.out", "w", stdout); 
#endif 
	ios_base::sync_with_stdio(false);
	int t = 1;
	//cin >> t; 
	while (t--)
		solve();

#ifdef DEBUG 
	cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif 
	return 0;
	
	}
int INF = 1000000000;
int d[101010];
int a[101010];
void solve() {
	int n;
	cin >> n;
	if(n == 1) {
		cout << 1 << endl;
		return;
	}
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	d[0] = -INF;
	for (int i=1; i<=n + 5; ++i)
		d[i] = INF;

	for (int i=0; i < n; i++) {
		int j = int (upper_bound (d, d + n, a[i]) - d);
		if (d[j-1] < a[i] && a[i] < d[j])
			d[j] = a[i];
	}
	
	int x = 0;
	for(int i = 0; ; ++i) {
		//cout << d[i] << ' ';
		if(d[i] == INF) {
			cout << i - 1 << endl;
			return;
		}
	}
}