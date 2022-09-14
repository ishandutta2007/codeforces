#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
typedef long long ll;
typedef long double ld;
 
using namespace std;

ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    ll p, q, b, g;
    for (int i = 0; i < n; i++) {
    	cin >> p >> q >> b;
    	g = gcd(p, q);
    	q /= g;
    	for (int j = 2; j < 100; j++)
    		if (b % j == 0) {
    			while (b % j == 0)
    				b /= j;
    			while (q % j == 0)
    				q /= j;
    		}
    	while (1) {
    		g = gcd(b, q);
    		if (g == 1)
    			break;
    		while (q % g == 0)
    			q /= g;
	   	}
	   	if (q == 1)
	   		cout << "Finite\n";
	   	else
	   		cout << "Infinite\n";
    }
}