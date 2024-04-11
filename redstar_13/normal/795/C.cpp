#include<bits/stdc++.h>

using namespace std;

int main()

{

	int n,i;

	scanf("%d",&n);

	if(n%2==0) printf("1");

	else printf("7");

	for(i=0;i<(n-2)/2;i++) printf("1");

	return 0;

}