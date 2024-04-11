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

vector<int> v[101010];

bool res[101010];

void solve() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		v[abs(a)].push_back(i);
	}
	
	li ans = 0;
	
	
	for(int i = 0; i <= 100005; ++i){
		int allHave = 0;
		for(int j = 0; j < n; ++j) {
			if(res[j])
				++allHave;
		}
		for(int pos: v[i]) {
			int invPositive = 0;
			for(int j = pos + 1; j < n ; ++j){
				if(res[j])
					++invPositive;
			}
			
			ans += min(invPositive, allHave - invPositive);
			
			
			res[pos] = true;
		}
		
	}
	
	cout << ans;
}