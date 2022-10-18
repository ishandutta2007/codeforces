#include<bits/stdc++.h>
using namespace std;
char a[150];
int main()
{
	int n;
	scanf("%d",&n);
	cin >> a;
	int s = 0;
	for(int i = 0;i<n;i++)
	{
		if (a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='y')
		{
			if (s==1) continue;
			else if (s==0) 
			{
				s=1;
				printf("%c",a[i]);
			}
		}
		else 
		{
			s=0;
			printf("%c",a[i]);
		}
	}
	return 0;
}