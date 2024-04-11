#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int s = (int)log2(n+0.8);
	printf("%d\n",s+1);
	return 0;
}