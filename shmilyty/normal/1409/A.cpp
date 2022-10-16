#include<bits/stdc++.h>
using namespace std;
int t,a,b;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&a,&b);
		cout<<(abs(a-b)+9)/10<<endl;
	}
	return 0;
}