#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int num1[200010],num2[200010];
int tree[200010],n;
void insert(int i,int j)
{
	for(;i<=n;i+=i&-i)
		tree[i]+=j;
}
int get(int i)
{
	int ans=0;
	for(;i;i-=i&-i)
		ans+=tree[i];
	return ans;
}
int kth(int i)
{
	int ans=0,now=0;
	for(int j=20;j>=0;j--)
		if(ans+(1<<j)>n||now+tree[ans+(1<<j)]>=i)
			continue;
		else
		{
			now+=tree[ans+(1<<j)];
			ans+=(1<<j);
		}
	return ans+1;
}
int main()
{
	int n1;
	cin>>n;
	for(n1=1;n1<=n;n1++)
	{
		scanf("%d",&num1[n1]);
		insert(num1[n1]+1,1);
		num1[n1]-=get(num1[n1]);
	}
	memset(tree,0,sizeof(tree));
	for(n1=1;n1<=n;n1++)
	{
		scanf("%d",&num2[n1]);
		insert(num2[n1]+1,1);
		num2[n1]-=get(num2[n1]);
	}	
	for(n1=n;n1>=1;n1--)
	{
		if(num1[n1]+num2[n1]>=n-n1+1)
			num1[n1-1]++;
		num1[n1]=(num1[n1]+num2[n1])%(n-n1+1);
	}
	memset(tree,0,sizeof(tree));
	for(n1=1;n1<=n;n1++)
		insert(n1,1);
	for(n1=1;n1<=n;n1++)
	{
		num1[n1]=kth(num1[n1]+1);
		insert(num1[n1],-1);
		printf("%d ",num1[n1]-1);
	}
		
}