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

char s[1010];
int cnt[30];

int main(){
 	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 	int n;
	scanf("%d %s", &n, s);
	int m = strlen(s);
	for(int i = 0; i < m; i++){
		cnt[s[i] - 'a']++;
	}
	for(int i = 0; i < 26; i++){
		if(cnt[i] % n != 0){
			printf("-1\n");
			return 0;
		}
	}
	int ptr = 0;
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < cnt[i] / n; j++){
			s[ptr++] = 'a' + i;
		}
	}
	s[ptr] = 0;
	for(int i = 0; i < n; i++){
		printf("%s", s);	
	}
	printf("\n");
	return 0;
}