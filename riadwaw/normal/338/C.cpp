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
typedef pair<int,int> pi;

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

li a[101010];
li rest[101010];
map<li, int> memo;
int div(li x){
	if(memo.find(x) != memo.end()) {
		return memo[x];
	}
	int& res = memo[x];
	for(li i = 2; i  * i <= x; ++i) {
		while(x % i == 0) {
			x /= i;
			++res;
		}
	}
	if(x > 1) {
		++res;
	}
	
	return res;
}

int rec(int index, int currentRoots, int n) {
	
	if(index == n) {
		int sum = n;
		if(currentRoots > 1)
			++sum;
		for(int i = 0; i < n; ++i) {
			int divisors = div(rest[i]);
			sum += divisors == 1 ? (a[i] == rest[i] ? 0: 1) : divisors;
		}
		return sum;
	}
	int mn = rec(index + 1, currentRoots + 1, n);
	
	for(int i = index + 1; i < n; ++i) {
		if(rest[i] % a[index] == 0) {
			rest[i] /= a[index];
			mn = min(mn, rec(index + 1, currentRoots, n));
			rest[i] *= a[index];
		}
	}
	
	return mn;
}

void solve() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		rest[i] = a[i];
	}
	
	sort(a, a + n);
	sort(rest, rest + n);
	cout << rec(0, 0, n);
}