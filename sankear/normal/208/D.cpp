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

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef complex <double> tc;

const double eps = 1e-9;
const double pi = acos(double(-1));
const int inf = int(1e9);

ll a[100], b[100], cnt[100];

int main(){
#ifdef HOME
	double start = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%I64d", &a[i]);
	}
	for(int i = 0; i < 5; i++){
		scanf("%I64d", &b[i]);
	}
	ll sum = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];
		for(int j = 4; j >= 0; j--){
			if(sum >= b[j]){
				cnt[j] += sum / b[j];
				sum %= b[j];
			}
		}
	}
	for(int i = 0; i < 5; i++){
		if(i > 0){
			printf(" ");
		}
		printf("%I64d", cnt[i]);
	}
	printf("\n%I64d\n", sum);
#ifdef HOME
	printf("time = %.18lf\n", (clock() - start) / CLOCKS_PER_SEC);
#endif
	return 0;
}