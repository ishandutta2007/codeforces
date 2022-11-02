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

typedef unsigned long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;

const double eps = 1e-18;
const double pi = acos(double(-1));
const int inf = int(1e9);

int main(){
#ifdef HOME
	double start = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
#endif
	string s;
	cin >> s;
	while(sz(s) >= 3 && s.substr(0, 3) == "WUB"){
		s = s.substr(3, sz(s) - 3);
	}
	while(sz(s) >= 3 && s.substr(sz(s) - 3, 3) == "WUB"){
		s = s.substr(0, sz(s) - 3);
	}
	int i = 0;
	bool fl = false;
	while(i < sz(s)){
		if(i + 2 < sz(s) && s.substr(i, 3) == "WUB"){
			if(!fl){
				cout << " ";
				fl = true;
			}
			i += 3;
			continue;
		}
		fl = false;
		cout << s[i++];
	}
	cout << endl;
	return 0;
}