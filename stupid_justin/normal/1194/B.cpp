#include<bits/stdc++.h>
#include<string>
#include<cstring>
#define N 5e4+5
#define MOD 1e9+7
#define inf 0x3f3f3f3f
int n,t,x,m;
char ch[400005];
int row[50005],line[50005];
using namespace std;
int main()
{
	cin>>t;
	while(t--)
	{
		memset(ch,'.',sizeof(ch));
		memset(row,0,sizeof(row));
		memset(line,0,sizeof(line));
		cin>>n>>m;
		int num1=inf;
		int num2=inf;
		bool flag=false;
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin>>ch[i*m+j];
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++) 
			{
				if (ch[i*m+j]=='.'){row[i]++;line[j]++;}
			}
		}
		for (int i=0;i<n;i++)num1=min(num1,row[i]);
		for (int j=0;j<m;j++)num2=min(num2,line[j]);
//		for (int i=0;i<n;i++) printf("row[%d]=%d\n",i,row[i]);
//		for (int j=0;j<m;j++) printf("line[%d]=%d\n",j,line[j]);
		if (num1+num2>=2)
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				if (row[i]==num1)
				if (line[j]==num2)
				if (ch[i*m+j]=='.')
				{
					flag=true;break;
				}
			}
		}
		if (flag) num1--;
		cout<<num1+num2<<endl;
	}
	return 0;
}