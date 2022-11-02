#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <queue>
#include <cassert>

using namespace std;

//#define HOME
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define next _next
#define rank _rank
#define prev _prev
#define sz(s) int((s).size())

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;

const double eps = 1e-9;
const double pi = acos(double(-1));
const int inf = int(1e9);
const int maxlen = 17;

ll d[maxlen + 10];

inline ll get(ll n){
	if(n == 0){
		return 0;
	}
	if(n < 10){
		return n;
	}
	vi s;
	while(n > 0){
		s.pb(n % 10);
		n /= 10;
	}
	reverse(s.begin(), s.end());
	ll ans = 0;
	for(int i = 1; i <= sz(s); i++){
		for(int j = 1; j <= 9; j++){
			if(i < sz(s)){
				ans += d[max(i - 2, 0)];
				continue;
			}
			if(s[0] < j){
				continue;
			}
			if(s[0] > j){
				ans += d[max(sz(s) - 2, 0)];
				continue;
			}
			for(int z = 1; z < sz(s); z++){
				if(z == sz(s) - 1){
					if(j <= s[z]){
						ans++;
					}
					continue;
				}
				for(int h = 0; h < s[z]; h++){
					ans += d[max(sz(s) - z - 2, 0)];
				}
			}
		}
	}
	return ans;
}

inline void init(){
	d[0] = 1;
	for(int i = 1; i <= maxlen; i++){
		d[i] = d[i - 1] * 10;
	}
}

int main(){
#ifdef HOME
	double start = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
#endif
	ll l, r;
	cin >> l >> r;
	init();
	ll ans = get(r) - get(l - 1);
	cout << ans << endl;
	return 0;
}