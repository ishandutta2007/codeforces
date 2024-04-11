#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d,e,f;
	scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
	int t = abs(b-a)*d;
	int s = abs(c-a)*e+abs(a-b)*e+3*f;
	if(t<s) printf("NO\n");
	else printf("YES\n");
	return 0;
}