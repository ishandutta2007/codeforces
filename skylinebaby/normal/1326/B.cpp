#include<bits/stdc++.h>
using namespace std;\
int a[212345];
int b[212345];
int x[212345];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &b[i]);
	a[0] = b[0];
	x[0] = 0;
	for(int i = 1; i < n; i++)
	{
		x[i] = max(x[i - 1], a[i - 1]);
		a[i] = x[i] + b[i];
	}
	for(int i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");
	return 0;
}