#include<bits/stdc++.h>
using namespace std;
const int N=2050;
int n,m;
int main()
{
	int i;
	cin>>n;
	m=(n/2)+1;
	printf("%d\n",m);
	for(i=1;i<=min(n,m);i++) printf("1 %d\n",i);
	for(i=1;i<=n-m;i++) printf("%d %d\n",m,i+1);
}