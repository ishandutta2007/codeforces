#include<bits/stdc++.h>
using namespace std;

stack<char> st;

int main()
{
	int ans=0;
	char s[101010];
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0;i<n;i++)
	{
		if(!st.empty())
		{
			if(st.top()==s[i])
			{
				ans++;
				st.pop();
			}
			
			else
			{
				st.push(s[i]);
			}
		}
		else
		{
			st.push(s[i]);
		}
		
	}
	if(ans%2==1)
	{
		printf("YES");
	}
	else printf("NO");
}