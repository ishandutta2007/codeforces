#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <double> tc;

const int inf = (int)1e9;

int a[200], b[200];

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int mina = inf, maxa = -inf;
	for(int i = 0; i < n; i++){
		mina = min(mina, a[i]);
		maxa = max(maxa, a[i]);
	}
	int ans = inf;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[j] == maxa){
				for(int z = 0; z < n; z++){
					b[z] = a[z];
				}
				int res = 0;
				for(int z = j; z > 0; z--){
					swap(b[z], b[z - 1]);
					res++;
				}
				for(int z = n - 1; z > 0; z--){
					if(b[z] == mina){
						res += n - 1 - z;
						break;
					}	
				}
				ans = min(ans, res);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}