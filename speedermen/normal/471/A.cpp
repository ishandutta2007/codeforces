#pragma comment(linker, "/STACK:100000000")
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <complex>
#include <string>
#include <bitset>
#include <vector>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef complex < double > cd;
 
const bool db = false;
 
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define sd second
#define fs first
 
#define inf 1000000007
#define nmax 200010
#define mmax 400010
#define eps 1e-7

int d[66];

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//freopen("message.in", "r", stdin); freopen("message.out", "w", stdout);
	for(int i = 0; i < 6; ++i)
		cin >> d[i];
	sort(d, d + 6);
	if(d[0] == d[3] && d[4] < d[5] || d[1] == d[4] && d[0] < d[5] || d[2] == d[5] && d[0] < d[1])
		cout << "Bear" << endl;
	else if(d[0] == d[3] && d[4] == d[5] || d[2] == d[5] && d[1] == d[0])
		cout << "Elephant" << endl;
	else
		cout << "Alien" << endl;
	//while(1);
	return 0;
}