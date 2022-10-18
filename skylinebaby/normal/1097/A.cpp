#include<bits/stdc++.h>
using namespace std;
int main()
{
	char x,y;
	cin>>x>>y;
	int flag = 0;
	for(int i = 0;i<5;i++)
	{
		char a,b;
		cin>>a>>b;
		if(a==x||b==y) flag = 1;
	}
	if(flag) printf("YES\n");
	else printf("NO\n");
	return 0; 
}