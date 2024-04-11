#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

#define maxn 1005000
#define maxc 1005

using namespace std;

int n, a1, b1, m, k, c1, c2;
int bal[maxn][2];
char ll[maxc], rr[maxc];

int update(const int &x, const char &aa, const char &bb){
	bal[x][0] = bal[x - 1][0];
	bal[x][1] = bal[x - 1][1];
	if(aa != bb){
		if(aa == 'R' && bb == 'S' || aa == 'S' && bb == 'P' || aa == 'P' && bb == 'R')++bal[x][1];
		else ++bal[x][0];
	}
	return 0;
}

int main(){
	scanf("%d", &n);
	scanf(" %s %s", ll, rr);
	m = strlen(ll);
	k = strlen(rr);
	c1 = c2 = 0;
	for(int i = 1; i <= m * k; ++i){
		update(i, ll[c1], rr[c2]);
		c1 = (c1 + 1) % m;
		c2 = (c2 + 1) % k;
	}
	int pp = n / (m * k), kp = n % (m * k);
	a1 = bal[m * k][0] * pp + bal[kp][0];
	b1 = bal[m * k][1] * pp + bal[kp][1];
	printf("%d %d\n", a1, b1);

	return 0;
}