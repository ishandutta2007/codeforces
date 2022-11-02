#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <complex>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define next _next
#define prev _prev
#define rank _rank

typedef long long ll;
typedef long long llong;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const ll MOD = ll(1e9 + 7);
const ll MOD2 = MOD * MOD;

int m;
ll d[60][60], nd[60][60];
bool bad[60][60];

inline int f(char ch){
	if(ch >= 'a' && ch <= 'z'){
		return ch - 'a';	
	}
	return ch - 'A' + 26;
}

inline void norm(ll &a, ll b){
	while(a >= b){
		a -= b;	
	}
}

void calc(ll n){
	if(n == 1){
		for(int i = 0; i < m; i++){
			d[i][i] = 1;
		}
		return;
	}
	if(n % 2 != 0){
		calc((n + 1) / 2);
		for(int i = 0; i < m; i++){
			for(int j = 0; j < m; j++){
				nd[i][j] = 0;
				for(int z = 0; z < m; z++){
					nd[i][j] += d[i][z] * d[z][j];
					norm(nd[i][j], MOD2);
				}
				nd[i][j] %= MOD;
			}
		}
		for(int i = 0; i < m; i++){
			for(int j = 0; j < m; j++){
				d[i][j] = nd[i][j];	
			}
		}
		return;
	}
	calc(n - 1);
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			nd[i][j] = 0;
			for(int z = 0; z < m; z++){
				if(!bad[z][j]){
					nd[i][j] += d[i][z];
					norm(nd[i][j], MOD);
				}
			}
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			d[i][j] = nd[i][j];	
		}
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("painting.in", "r", stdin);
    //freopen("painting.out", "w", stdout);
	ll n;
	int k;
	cin >> n >> m >> k;
	for(int i = 0; i < k; i++){
		string s;
		cin >> s;
		bad[f(s[0])][f(s[1])] = true;
	}
	calc(n);
	ll ans = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			ans += d[i][j];
			norm(ans, MOD);
		}
	}
	cout << ans << endl;
	return 0;
}