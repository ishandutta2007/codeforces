#include<bits/stdc++.h>
using namespace std;
int t,a,b;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		cout<<min(a,min(b,(a+b)/3))<<endl;
	}
	return 0;
}