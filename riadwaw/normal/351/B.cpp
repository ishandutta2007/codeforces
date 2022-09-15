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

int a[101010];

void solve() {
	int n;
	cin >> n;
	for(int i = 0; i < 2 * n; ++i) {
		cin >> a[i];
	}
	
	int ans = 0;
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j) {
			
			if(a[i] < a[j])
				++ans;
		}
			
	}
	
	if(ans % 2)
		cout << ans * 2 - 1;
	else
		cout << 2 * ans;
}