#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
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
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define LLD "%lld"
#else
#define eprintf(...) 42
#define LLD "%I64d"
#endif
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash

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

char s[100100];

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	gets(s);
	int n = strlen(s), i = 0;
	while(i < n){
		if(s[i] == ' '){
			i++;
			continue;
		}
		if(s[i] == '"'){
			int j = i + 1;
			while(s[j] != '"'){
				j++;
			}
			printf("<");
			for(int z = i + 1; z < j; z++){
				printf("%c", s[z]);
			}
			printf(">\n");
			i = j + 1;
			continue;
		}
		int j = i;
		while(j + 1 < n && s[j + 1] != ' '){
			j++;
		}
		printf("<");
		for(int z = i; z <= j; z++){
			printf("%c", s[z]);
		}
		printf(">\n");
		i = j + 1;
	}
	return 0;
}