#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>

using namespace std;
int n,m;
char str[233333];
int fl[233333];
vector<int> ans[233333];
int top=0;
queue<int> q,qq;
int main()
{
	scanf("%s",str+1);
	n=strlen(str+1);
	for(int i=1;i<=n;i++)
	{
		if(str[i]=='0')
		{
			if(q.empty())
			{
				qq.push(++top);
				ans[top].push_back(i);
			}
			else
			{
				ans[q.front()].push_back(i);
				qq.push(q.front());
				q.pop();
			}
		}
		else
		{
			if(qq.empty())return printf("-1\n"),0;
			else
			{
				ans[qq.front()].push_back(i);
				q.push(qq.front());
				qq.pop();
			}
		}
	}
	if(!q.empty())return printf("-1\n"),0;
	printf("%d\n",top);
	for(int i=1;i<=top;i++)
	{
		printf("%d ",ans[i].size());
		for(auto x:ans[i])printf("%d ",x);
		printf("\n");
	}
	return 0;
}