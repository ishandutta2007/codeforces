#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
 
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
#define hash _hash
#ifdef LOCAL
#define LLD "%I64d"
#else
#define LLD "%I64d"
#endif
 
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;
 
const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

char s[100100];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	scanf("%s", s);
	int n = strlen(s);
	for(int i = 0; i < n; i++){
		if(s[i] == '0'){
			s[i] = 0;
			printf("%s%s\n", s, s + i + 1);
			return 0;
		}
	}
	printf("%s\n", s + 1);
	return 0;
}