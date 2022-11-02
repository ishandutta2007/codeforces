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
#include <complex>
#include <queue>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define next _next
#define prev _prev
#define rank _rank
#define sz(s) int((s).size())
#define fs first
#define sc second

typedef long long ll;
typedef unsigned long long ull;
typedef complex <double> tc;
typedef pair <int, int> pii;
typedef vector <int> vi;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

int a[100100], b[100100];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b, b + n);
	int k = 0;
	for(int i = 0; i < n; i++){
		if(a[i] != b[i]){
			k++;
		}
	}
	if(k <= 2){
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}