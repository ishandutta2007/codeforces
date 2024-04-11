#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	if (n%10>5) printf("%d\n",10*(n/10)+10);
	else printf("%d\n",10*(n/10));
}