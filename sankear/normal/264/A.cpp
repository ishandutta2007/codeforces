#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
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
#define link _link

typedef long long ll;
typedef long long llong;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

int n;
char s[1000100];

void gen(int x){
	if(x >= n){
		return;
	}
	if(s[x] == 'l'){
		gen(x + 1);
		printf("%d\n", x + 1);
		return;
	}
	printf("%d\n", x + 1);
	gen(x + 1);
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	scanf("%s", s);
	n = strlen(s);
	gen(0);
	return 0;
}