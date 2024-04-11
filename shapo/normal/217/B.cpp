#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <set>

#define maxn 1005000

using namespace std;

char s[maxn], cur[maxn];
int lenc;
int num, n, r, mn, cr;
int q[maxn][2];

int gcd(int a, int b){
	if(a < b)swap(a, b);
	while(b){
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int num_f(int a, int b){
	int res = 0;
	if(a < b)swap(a, b);
	while(b){
		int t = a % b;
		res += a / b;
		a = b;
		b = t;
	}
	return res;
}

int add_q(int a, int b){
	q[num][0] = a;
	q[num++][1] = b;
	return 0;
}

int gen_s(int a, int b){
	//printf("a = %d, b = %d\n", a, b);
	lenc = 0;
	cur[0] = 0;
	while(b != 0 && a != 0){
		if(a >= b){
			cur[lenc++] = 'T';
			a -= b;
		}
		else{
			cur[lenc++] = 'B';
			b -= a;
		}
	}
	cr = 0;
	for(int i = 0; i < lenc - 1; ++i)
		if(cur[i] == cur[i + 1])++cr;
	//printf("cur = %s\n", cur);
	if(cr < mn){
		mn = cr;
		for(int i = 0; i < lenc; ++i)
			s[i] = cur[lenc - i - 1];
		if(s[lenc - 1] == 'T')
			s[lenc] = 'B';
		else
			s[lenc] = 'T';
	}	
	return 0;
}

int main(){
	scanf("%d%d", &n, &r);
	if(n == 1 && r == 1){
		printf("0\nT\n");
		return 0;
	}
	num = 0;
	for(int i = 1; 2 * i <= r; ++i){
		if(gcd(i, r - i) == 1){
			int cur = num_f(r - i, i) + 1;
			if(cur == n)add_q(r - i, i);
		}
	}
	if(num == 0){
		printf("IMPOSSIBLE\n");
		return 0;
	}
	mn = maxn + 2;
	for(int i = 0; i < num; ++i){
		gen_s(q[i][0], q[i][1]);
		gen_s(q[i][1], q[i][0]);
	}
	printf("%d\n", mn);
	printf("%s\n", s);
	return 0;
}