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

using namespace std;

bool can[10][10];
char s[1010], t[1010];

inline int get(char ch){
	if(ch == 'S'){
		return 0;
	}
	if(ch == 'P'){
		return 1;
	}
	return 2;
}

inline int gcd(int a, int b){
	while(b > 0){
		a %= b;
		swap(a, b);
	}
	return a;
}

int main(){
	//freopen("b.in", "r", stdin);
	//freopen("b.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	can[2][0] = can[0][1] = can[1][2] = true;
	int n;
	scanf("%d %s %s", &n, s, t);
	int m = strlen(s), k = strlen(t);
	int nok = (m * k) / gcd(m, k), add1 = 0, add2 = 0;
	for(int i = 0; i < nok; i++){
		if(can[get(s[i % m])][get(t[i % k])]){
			add2++;
		}
		if(can[get(t[i % k])][get(s[i % m])]){
			add1++;
		}
	}
	int ans1 = add1 * (n / nok), ans2 = add2 * (n / nok);
	for(int i = 0; i < n % nok; i++){
		if(can[get(s[i % m])][get(t[i % k])]){
			ans2++;
		}
		if(can[get(t[i % k])][get(s[i % m])]){
			ans1++;
		}
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}