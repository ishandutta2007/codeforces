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

const int maxch = (int)1e4;
const int block = 1500;

char s[100];
int a[100100];
int lst[maxch + 10];
int add[350];
int b[350][maxch + 10];
bool can[maxch + 10];

inline bool good(int a){
	while(a > 0){
		int b = a % 10;
		if(b != 4 && b != 7){
			return false;
		}
		a /= 10;
	}
	return true;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		b[i / block][a[i]]++;
	}
	int sz = 0;
	for(int i = 1; i <= maxch; i++){
		if(good(i)){
			can[i] = true;
			lst[sz++] = i;
		}
	}
	for(int i = 0; i < m; i++){
		int l, r;
		scanf("\n%s %d %d", s, &l, &r);
		l--;
		r--;
		int nl = l / block;
		int nr = r / block;
		if(strcmp(s, "add") == 0){
			int d;
			scanf("%d", &d);
			if(nl == nr){
				for(int j = l; j <= r; j++){
					b[nl][a[j]]--;
					a[j] += d;
					b[nl][a[j]]++;
				}
			}
			else{
				for(int j = l; j < (nl + 1) * block; j++){
					b[nl][a[j]]--;
					a[j] += d;
					b[nl][a[j]]++;
				}
				for(int j = nr * block; j <= r; j++){
					b[nr][a[j]]--;
					a[j] += d;
					b[nr][a[j]]++;
				}
				for(int j = nl + 1; j < nr; j++){
					add[j] += d;
				}
			}
			continue;
		}
		int ans = 0;
		if(nl == nr){
			for(int j = l; j <= r; j++){
				if(can[a[j] + add[nl]]){
					ans++;
				}
			}
		}
		else{
			for(int j = l; j < (nl + 1) * block; j++){
				if(can[a[j] + add[nl]]){
					ans++;
				}
			}
			for(int j = nr * block; j <= r; j++){
				if(can[a[j] + add[nr]]){
					ans++;
				}
			}
			for(int j = nl + 1; j < nr; j++){
				for(int z = 0; z < sz; z++){
					if(lst[z] > add[j]){
						ans += b[j][lst[z] - add[j]];
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}