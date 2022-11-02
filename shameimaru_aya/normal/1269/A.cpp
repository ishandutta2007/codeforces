#include<bits/stdc++.h>
using namespace std;
int n , flag;
int main()
{
	scanf("%d" , &n);
	if(n > 1) printf("%d %d" , 3 * n , 2 * n);
	else printf("9 8");
	return 0;
}