#include<bits/stdc++.h>
using namespace std;
char s[111111];
int a[26];
main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	cin >> s;
	int mm = 26;
	int pp = 0;
	for(int i = 0;i<n;i++)
	{
		a[s[i]-'a'] = 1;
		mm = min(mm,s[i]-'a');
		pp = max(pp,s[i]-'a');
	}
	int flag;
	char xx = 'a'+mm;
	char yy = 'a'+pp;
	if (k>n)
	{
		for(int i = 0;i<n;i++)
		{
			cout << s[i];
		}
		for(int i = n;i<k;i++)
		{
			cout << xx;
		}
	}
	else 
	{
		for(int i = k-1;i>=0;i--)
		{
			if (s[i]-'a'<pp) 
			{
				flag = i;	
				break;
			}
		}
		char  qq;
		for(int i = s[flag]-'a' + 1;i<26;i++)
		{
			if(a[i]==1)
			{
				qq=i+'a';
				break;
			}
		}
		for(int i = 0;i<flag;i++)
		{
			cout << s[i];
		}
		cout << qq;
		for(int i = flag +1;i<k;i++)
		{
			cout<<xx;
		}
	}
	printf("\n");
	return 0;
}