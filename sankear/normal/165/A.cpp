#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <complex>
#include <queue>
#include <deque>
#include <functional>

using namespace std;

struct point{
	int x, y;
};

point p[300];

int main(){
	//freopen("caravans.in", "r", stdin);
	//freopen("caravans.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &p[i].x, &p[i].y);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		bool f1 = false, f2 = false, f3 = false, f4 = false;
		for(int j = 0; j < n; j++){
			if(p[i].x == p[j].x && p[i].y < p[j].y){
				f1 = true;
			}
			if(p[i].x == p[j].x && p[i].y > p[j].y){
				f2 = true;
			}
			if(p[i].y == p[j].y && p[i].x < p[j].x){
				f3 = true;
			}
			if(p[i].y == p[j].y && p[i].x > p[j].x){
				f4 = true;
			}
		}
		if(f1 && f2 && f3 && f4){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}