#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	if(n % 2) printf("%d", (n + 1)/2*(n + 1)/2);
	else printf("%d", (n/2)*(n/2 + 1));
}