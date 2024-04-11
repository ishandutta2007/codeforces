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
string x[210],pr[210],l[210];
int pre[210][25],ls[210][25],len[210];
bitset<17000> hv[210][15];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		
		len[i]=x[i].length();
		pr[i]=l[i]=x[i];
		for(int j=0;j<min(len[i],21);j++)
			pre[i][j+1]=pre[i][j]*2+(x[i][j]-48);
		int now=1;
		for(int j=len[i]-1;j>=max(0,len[i]-20);j--)
		{
			ls[i][len[i]-j]=ls[i][len[i]-j-1]+now*(x[i][j]-48);
			now*=2;
		}
		for(int j=1;j<=14;j++)
			for(int k=0;k<=len[i]-j;k++)
			{
				int now=0;
				for(int l=k;l<k+j;l++)
					now=now*2+x[i][l]-48;
				hv[i][j][now]=1;
			}
	}
	int m;
	cin>>m;
	for(int i=n+1;i<=n+m;i++)
	{
		int t1,t2;
		cin>>t1>>t2;
		len[i]=len[t1]+len[t2];
		if(len[t1]>100)
			pr[i]=pr[t1];
		else
			pr[i]=x[t1]+pr[t2];
		if(pr[i].length()>100)
			pr[i]=pr[i].substr(0,100);
		if(len[t2]>100)
			l[i]=l[t2];
		else
			l[i]=l[t1]+x[t2];
		if(l[i].length()>100)
			l[i]=l[i].substr(l[i].length()-100,100);	
		if(len[t1]<=100&&len[t2]<=100)
			x[i]=x[t1]+x[t2];
		for(int j=0;j<min((int)pr[i].length(),21);j++)
			pre[i][j+1]=pre[i][j]*2+(pr[i][j]-48);
		int now=1;
		for(int j=l[i].length()-1;j>=max(0,(int)l[i].length()-20);j--)
		{
			ls[i][l[i].length()-j]=ls[i][l[i].length()-j-1]+now*(l[i][j]-48);
			now*=2;
		}			
		if(len[i]>100)
			len[i]=101;
		int ans=0;
		for(int j=1;j<=14;j++)
		{
			hv[i][j]=hv[t1][j]|hv[t2][j];
			for(int k=1;k<j;k++)
				if(len[t1]>=k&&len[t2]>=j-k)
					hv[i][j][ls[t1][k]*(1<<(j-k))+pre[t2][j-k]]=1;
			if(hv[i][j].count()==(1<<j))
				ans=j;
		}
		printf("%d\n",ans);
	}
		
}