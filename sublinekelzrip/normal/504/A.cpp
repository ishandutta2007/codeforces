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
int num[100010],p[100010];
queue<int> q;
int x[100010][2],y=0;
int main()
{
	int n,n1;
	cin>>n;
	if(n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	for(n1=0;n1<n;n1++)
		scanf("%d%d",&num[n1],&p[n1]);
	for(n1=0;n1<n;n1++)
		if(num[n1]==1)
			q.push(n1);
	while(!q.empty())
	{
		int z=q.front();
		q.pop();
		if(num[z]==0)
			continue;
		y++;
		x[y][0]=z;
		x[y][1]=p[z];
		num[p[z]]--;
		p[p[z]]^=z;
		if(num[p[z]]==1)
			q.push(p[z]);
	}
	cout<<y<<endl;
	for(n1=1;n1<=y;n1++)
		cout<<x[n1][0]<<' '<<x[n1][1]<<endl;
}