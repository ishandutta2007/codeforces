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

bool prime[1000100];
int sum[1000100];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("operators.in", "r", stdin);
	//freopen("operators.out", "w", stdout);
	int a, b, k;
	scanf("%d %d %d", &a, &b, &k);
	for(int i = 2; i <= b; i++){
		prime[i] = true;
	}
	for(int i = 2; i * i <= b; i++){
		if(prime[i]){
			for(int j = i * i; j <= b; j += i){
				prime[j] = false;
			}
		}
	}
	for(int i = a; i <= b; i++){
		sum[i] = sum[i - 1] + prime[i];
	}
	int ans = -1, l = 1, r = b - a + 1;
	while(l <= r){
		int mid = (l + r) / 2;
		bool fl = true;
		for(int i = a; i <= b - mid + 1; i++){
			if(sum[i + mid - 1] - sum[i - 1] < k){
				fl = false;
				break;
			}
		}
		if(fl){
			ans = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}