#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin>>n;
	if(n&1) puts("0");
	else printf("%d",(int)pow(2,n/2));
	return 0;
}