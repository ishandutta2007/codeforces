#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <string.h>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <algorithm>
#include <bitset>

using namespace std;

bool check(int a, int b) {return (b >= a - 1 && b <= 2 * (a + 1));}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int a1, a2, b1, b2;
	cin >> a1 >> a2;
	cin >> b1 >> b2;
	if (check(a1, b2) || check(a2, b1))
		printf("YES\n"); else printf("NO\n");
	return 0;
}