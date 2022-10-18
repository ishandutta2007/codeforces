#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	if (m<n) swap(m,n);
	int i = m-n;
	int s = i/2;
	i = i-s;
	int ans = i*(i+1)/2+s*(s+1)/2;
	printf("%d\n",ans);
	return 0;
}