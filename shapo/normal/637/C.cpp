#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector <int> vi;

#define pb push_back
#define mp make_pair

template <class T> inline T sqr(const T& x) { return x * x; }
template <class T> inline void updMin(T& a, const T& b) { if (b < a) a = b; }
template <class T> inline void updMax(T& a, const T& b) { if (b > a) a = b; }

vector<string> a; 

int cross(int i, int j) {
    int neq = 0; 
    for (int t = 0; t < 6; t++) {
        if (a[i][t] != a[j][t]) neq++; 
    }
    return (neq + 1) / 2; 
}

int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	
	int n; 
	cin >> n; 
	
	a.resize(n); 
	for (int i = 0; i < n ; i++) {
	    cin >> a[i]; 
	}
	
	if (n == 1) {
	    cout << 6 << "\n"; 
	} else {
	    int ans = 6; 
	    for (int i = 0; i < n; i++) {
	        for (int j = i + 1; j < n; j++) {
	            ans = min(ans, cross(i, j) - 1); 
	        }
	    }
	    cout << ans << "\n"; 
	}
	

    return 0;
}