//#pragma comment(linker, "/STACK:20000000")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

const int SIZE = 2<<20;

int n;
char a[SIZE];
char b[SIZE];
int k[2][2];
int score[2];

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	scanf("%s%s", a, b);

	for (int i = 0; i<2*n; i++)
		k[a[i]-'0'][b[i]-'0']++;

	for (int i = 0; i<2*n; i++) {
		int t = i&1;

		if (k[1][1]) {
			score[t]++;
			k[1][1]--;
		}
		else if (k[!t][t]) {
			score[t]++;
			k[!t][t]--;
		}
		else if (k[t][!t]) {
			k[t][!t]--;
		}
		else if (k[0][0]) {
			k[0][0]--;
		}
		else assert(0);
	}

	printf("%s\n", (score[0] == score[1] ? "Draw" : (score[0] > score[1] ? "First" : "Second")));

	return 0;
}