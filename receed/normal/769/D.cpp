// ConsoleApplication1.cpp:      .
//

//#define _CRT_SECURE_NO_WARNINGS
//#include "stdafx.h"
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int n, k, t, c;
vector<int>a(16384, 0);

int f(int pos, int ch) {
	if (ch == k) return k?a[c]:a[c]-1;
	if (pos >= 14) return 0;
	c = c ^ (1 << pos);
	int x = f(pos + 1, ch+1);
	c = c ^ (1 << pos);
	return x + f(pos + 1, ch);
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i = 0; i < n; i++) {
		scanf("%d",&t);
		a[t]++;
	}
	long long ans = 0,r;
	for (int i = 0; i < 16384; i++) {
		c = i;
		r = f(0, 0);
		ans += r*a[i];
	}
	printf("%I64d",ans/2);
	return 0;
}