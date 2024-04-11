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

struct tp{
	int x, y, r;
};

int n;
tp p[2000]; 

inline int sqr(int a){
	return a * a;
}

inline bool bad(int x, int y){
	for(int i = 0; i < n; i++){
		if(sqr(p[i].x - x) + sqr(p[i].y - y) <= sqr(p[i].r)){
			return false;
		}
	}
	return true;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int x1, y1, x2, y2;
	scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &p[i].x, &p[i].y, &p[i].r);
	}
	if(x1 > x2){
		swap(x1, x2);
	}
	if(y1 > y2){
		swap(y1, y2);
	}
	int ans = 0;
	for(int i = y1; i <= y2; i++){
		if(bad(x1, i)){
			ans++;
		}
		if(bad(x2, i)){
			ans++;
		}
	}
	for(int i = x1 + 1; i < x2; i++){
		if(bad(i, y1)){
			ans++;
		}
		if(bad(i, y2)){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}