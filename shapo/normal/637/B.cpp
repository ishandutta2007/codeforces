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

int likes_max = 0; 
int likes_leader = -1; 

unordered_set<string> names_used; 
vector<string> names; 

int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	
	int n; 
	cin >> n; 
	
	names.resize(n); 
	for (int i = 0; i < n ; i++) {
	    cin >> names[i]; 
	}
	
	for (int i = n - 1; i >= 0; i--) {
	    if (names_used.find(names[i]) == names_used.end()) {
	        names_used.insert(names[i]); 
	        cout << names[i] << "\n"; 
	    }
	}

    return 0;
}