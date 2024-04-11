#include<bits/stdc++.h>
using namespace std;
int st[501010];
int sb[501010];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	{
		string x;
		cin>>x;
		int t = 0; 
		int a = 0;
		for(int j = 0;j<x.length();j++)
		{
			if(x[j]=='(') a++;
			else a--;
			t = min(a,t);
		}
		if(t>=0) st[a] ++;
		else 
		{
			a = 0;
			t = 0;
			for(int j = x.length()-1;j>=0;j--)
			{
				if(x[j]==')') a++;
				else a--;
				t = min(a,t);
			}
			if(t>=0) sb[a]++;
		}
	}
	int ans = 0;
	for(int i = 1;i<501010;i++) ans += min(sb[i],st[i]);
	ans += (sb[0]+st[0])/2;
	printf("%d\n",ans);
	return 0;
}